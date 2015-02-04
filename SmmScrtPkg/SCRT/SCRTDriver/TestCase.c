/*++
 Copyright (c) 2009, Intel Corporation
 All rights reserved. 

 This UEFI SCRT ("Software") is furnished under license and may only be used or copied
 in accordance with the terms of that license UEFI Contributor Agreement.
 No license, express or implied, by estoppel or otherwise, to any intellectual property
 rights is granted by this document. The Software is subject to change without notice,
 and should not be construed as a commitment by Intel Corporation to market, license,
 sell or support any product or technology. Unless otherwise provided for in the license
 under which this Software is provided, the Software is provided AS IS, with no warranties
 of any kind, express or implied. Except as expressly permitted by the Software license,
 neither Intel Corporation nor its suppliers assumes any responsibility or liability
 for any errors or inaccuracies that may appear herein.
--*/
/*++

Module Name:

  TestCase.c

--*/

#include "SCRTDriver.h"


extern CHAR16                *gVarName;
extern CHAR16                *gTestRecordName;
extern EFI_RUNTIME_SERVICES  *VRT;

VOID
MemZero (
 VOID       *Addr,
 UINTN      Size
 )
{
  volatile UINT8   *Pointer;
  Pointer = (UINT8*)Addr;
  
  while (Size-- != 0) {
    *(Pointer++) = 0;
  }
}

VOID
InitVariableRecord (
  CONF_INFO    *ConfigData
  )
/*++

Routine Description:

  Initialize the global Variable which is used to record the test result.

Arguments:
   
   NONE
   
Returns:

   NONE
--*/   
{
  TEST_RECORD   TestRecord;
  UINT32        VariableAttr;
  EFI_GUID      VariableTestGuid = TEST_RECORD_GUID;

  VariableAttr = (EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE|EFI_VARIABLE_BOOTSERVICE_ACCESS);

  MemZero(&TestRecord,sizeof(TEST_RECORD));
  TestRecord.Request.TestData = (UINT16)ConfigData->InfoData;
  
  //
  // Clear "TestRecord" variable if it exists
  //
  VRT->SetVariable (
         gTestRecordName,                          
         &VariableTestGuid,                        
         VariableAttr,                             
         0,                                        
         (VOID*)NULL                               
         );
  //
  // Set "TestRecord" variable
  //
  VRT->SetVariable (
         gTestRecordName,     
         &VariableTestGuid,   
         VariableAttr,        
         sizeof(TEST_RECORD), 
         &TestRecord          
         );
}

VOID
SetVariableRecord (
  TEST_RECORD      *TestPoint
  )
{
  UINTN         DataSize;
  UINT32        VariableAttr;
  EFI_STATUS    Status;
  TEST_RECORD   TestRecord;
  EFI_GUID      VariableTestGuid = TEST_RECORD_GUID;

  DataSize     = sizeof(TEST_RECORD);

  VariableAttr = (EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE|EFI_VARIABLE_BOOTSERVICE_ACCESS);
  
  //
  // First, get the previous record variable.
  //
  Status = VRT->GetVariable (
                  gTestRecordName,     
                  &VariableTestGuid,   
                  NULL,                
                  &DataSize,           
                  &TestRecord           
                  );
  if (EFI_ERROR(Status)) {
    return ;
  }

  //
  // Second, clear the previous record variable
  //
  Status = VRT->SetVariable (
                  gTestRecordName,                             
                  &VariableTestGuid,                        
                  VariableAttr,                             
                  0,                                        
                  (VOID*)NULL                               
                  );

  if (EFI_ERROR(Status)) {
    return ;
  }
  
  TestRecord.Result.TestData |= TestPoint->Result.TestData;

  //
  // Finally, set the latest record variable.
  //
  Status = VRT->SetVariable (
                  gTestRecordName,   
                  &VariableTestGuid, 
                  VariableAttr,      
                  sizeof(TEST_RECORD),
                  &TestRecord         
                  );
  if (EFI_ERROR(Status)) {
    return ;
  }
}


VOID
EfiVariableTestVirtual (
  CONF_INFO  *ConfigData
  )
/*++

Routine Description:

  Test Variable related Runtime Service in runtime phase.

Arguments:
   
   NONE
   
Returns:

   NONE
--*/   
{
  UINTN                 DataIndex;
  UINTN                 DataSize;
  UINTN                 VariableNameSize;
  EFI_GUID              VendorGuid; 
  EFI_STATUS            Status;
  UINT8                 Data[MAX_BUFFER_SIZE];
  UINT8                 TestData[MAX_BUFFER_SIZE];
  CHAR16                VariableName[MAX_BUFFER_SIZE];
  UINT64                MaximumVariableStorageSize;
  UINT64                RemainingVariableStorageSize;
  UINT64                MaximumVariableSize;
  UINT32                VariableAttr;
  TEST_RECORD           TestPoint;
  EFI_GUID              VariableTestGuid = VARIABLE_TEST_GUID;
  EFI_TEST_ASSERTION    AssertionType = EFI_TEST_ASSERTION_FAILED;

  VariableAttr = (EFI_VARIABLE_RUNTIME_ACCESS|EFI_VARIABLE_NON_VOLATILE|EFI_VARIABLE_BOOTSERVICE_ACCESS);
 
  //
  // Put 10 test variable in list
  //
  for (DataIndex = 0; DataIndex < 10; DataIndex ++) {
    Data[DataIndex] = (UINT8)DataIndex;
  }

  if (ConfigData->BitMap.SetVariable) {
    //
    // Set a "UEFIRuntimeVariable" variable, and its datasize is 8 Bytes.
    //
    Port80(0x11);    
    Status = VRT->SetVariable (
                    gVarName,                        
                    &VariableTestGuid,               
                    VariableAttr,                    
                    8,                               
                    Data                             
                    );
    
    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;

    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid11,
      "RT.SetVariable - Set a test variable named UEFIRuntimeVariable, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );

    //
    // Clear "UEFIRuntimeVariable" variable
    //
    Port80(0x12);    
    Status = VRT->SetVariable (
                    gVarName,                  
                    &VariableTestGuid,         
                    VariableAttr,              
                    0,                         
                    (VOID*)NULL                
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
  
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid12,
      "RT.SetVariable - Clear a test variable named UEFIRuntimeVariable, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );

    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.SetVariable = 1;
    SetVariableRecord(&TestPoint);
  }

  if (ConfigData->BitMap.GetVariable) {
    //
    // Firstly, set "UEFIRuntimeVariable" variable for test.
    //
    Port80(0x21);    
    Status = VRT->SetVariable (
                    gVarName,                     
                    &VariableTestGuid,            
                    VariableAttr,                 
                    8,                            
                    Data                          
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
  
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid21,
      "RT.SetVariable - Set a test variable named UEFIRuntimeVariable, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );

    
    //
    // Get "UEFIRuntimeVariable" variable.
    //
    DataSize = MAX_BUFFER_SIZE;
    Port80(0x22); 
    Status = VRT->GetVariable (
                    gVarName,                   
                    &VariableTestGuid,          
                    NULL,                       
                    &DataSize,                  
                    TestData                    
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
  
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid22,    
      "RT.GetVariable - Get the test variable named UEFIRuntimeVariable, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );
  
    //
    // Clear "UEFIRuntimeVariable" variable
    //
    Port80(0x23);    
    Status = VRT->SetVariable (
                    gVarName,                     
                    &VariableTestGuid,            
                    VariableAttr,                 
                    0,                            
                    (VOID*)NULL                   
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
  
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid23,
      "RT.SetVariable - Clear a test variable named UEFIRuntimeVariable, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );   

    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.GetVariable = 1;
    SetVariableRecord(&TestPoint);
  }
  
  //
  // Loop GetNextVariableName to find whether a "UEFIRuntimeVariable" variable exists.
  //
  if (ConfigData->BitMap.GetNextVariable) {
    //
    // Firstly, set "UEFIRuntimeVariable" variable for test.
    //
    Port80(0x31); 
    Status = VRT->SetVariable (
                    gVarName,                
                    &VariableTestGuid,       
                    VariableAttr,            
                    8,                       
                    Data                     
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
  
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid31,
      "RT.SetVariable - Set a test variable named UEFIRuntimeVariable, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );
    
    
    VariableName[0] = '\0';
    while (TRUE) {
      VariableNameSize = MAX_BUFFER_SIZE * sizeof(CHAR8);
      Port80(0x32);        
      Status = VRT->GetNextVariableName (
                      &VariableNameSize,         
                      VariableName,              
                      &VendorGuid                
                      );
      if (EFI_ERROR(Status)) {
        if (EFI_NOT_FOUND == Status) 
          AssertionType = EFI_TEST_ASSERTION_PASSED;
        else
          AssertionType = EFI_TEST_ASSERTION_FAILED;

        RecordAssertion (
          AssertionType,
          gSCRTAssertionGuid32,        
          "RT.GetNextVariableName - Get the next variable name should be EFI_SUCCESS/EFI_NOT_FOUND",
          "%a:%d:Status - %r, Expected - %r",
          __FILE__,
          __LINE__,
          Status,
          EFI_NOT_FOUND
          );
        break;
      }
      else {
      	 AssertionType = EFI_TEST_ASSERTION_PASSED;
        if ((EfiCompareMem (VariableName, L"UEFIRuntimeVariable", 19*sizeof(CHAR16)) == 0) &&
           (EfiCompareMem (&VendorGuid, &VariableTestGuid, sizeof(EFI_GUID)) == 0)) {
            RecordAssertion (
            AssertionType,
            gSCRTAssertionGuid32,        
            "RT.GetNextVariableName - Get the next variable name should be EFI_SUCCESS/EFI_NOT_FOUND",
            "%a:%d:Status - %r, Expected - %r",
            __FILE__,
            __LINE__,
            Status,
            EFI_SUCCESS
            ); 
          break;
        }
      }
    }

    //
    // Clear "UEFIRuntimeVariable" variable
    //
    Port80(0x33);    
    Status = VRT->SetVariable (
                    gVarName, 
                    &VariableTestGuid,     
                    VariableAttr,          
                    0,                     
                    (VOID*)NULL            
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
  
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid33,
      "RT.SetVariable - Clear a test variable named UEFIRuntimeVariable, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );    

    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.GetNextVariable = 1;
    SetVariableRecord(&TestPoint);
  }

  //
  // Call QueryVariableInfo to get variable information.
  //
  if (ConfigData->BitMap.QueryVariable) {
    Port80(0x41);      
    Status = VRT->QueryVariableInfo (
                    VariableAttr,                       
                    &MaximumVariableStorageSize,        
                    &RemainingVariableStorageSize,      
                    &MaximumVariableSize                
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;

    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid41,    
      "RT.QueryVariableInfo - Query Variable Information of the platform should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );
    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.QueryVariable = 1;
    SetVariableRecord(&TestPoint);    
  }
}



VOID
EfiTimeTestVirtual (
  CONF_INFO      *ConfigData
  )
/*++

Routine Description:

  Test Time related Runtime Service in runtime phase.

Arguments:
   
   NONE
   
Returns:

   NONE
--*/   
{
  EFI_TIME              Time;
  EFI_TIME              OldTime;
  BOOLEAN               Enable;
  BOOLEAN               Pending;
  EFI_STATUS            Status;
  TEST_RECORD           TestPoint;
  EFI_TEST_ASSERTION    AssertionType = EFI_TEST_ASSERTION_FAILED;  
  //
  // Get the current time and data information.
  //
  if (ConfigData->BitMap.GetTime) {
    Port80(0x51);     
    Status = VRT->GetTime (
                    &Time,
                    NULL
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;

    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid51,    
      "RT.GetTime - Get the current time and date information should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );
    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.GetTime = 1;
    SetVariableRecord(&TestPoint);        
  }

  if (ConfigData->BitMap.SetTime) {
    //
    // Firstly , Get current time for test.
    //
    Port80(0x61);  
    Status = VRT->GetTime (
                    &OldTime,
                    NULL
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
 
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid61,    
      "RT.GetTime - Get the current time and date information should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );

    //
    // Restore the previous time.
    // 
    Port80(0x62); 
    Status = VRT->SetTime (
                    &OldTime
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
 
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid62,    
      "RT.SetTime - Set the previous time information shoule be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );
    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.SetTime = 1;
    SetVariableRecord(&TestPoint);            
  }

  
  //
  // Get the current time setting.
  //
  if (ConfigData->BitMap.SetWakeupTime) {
    Port80(0x71);  
    Status = VRT->GetTime (
                    &Time,
                    NULL
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
    
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid71,
      "RT.GetTime  - Get the current time and date information to modify, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );
    //
    // Set the system wakeup alarm clock time to 1 hour later.
    //
    Port80(0x72);    
    Time.Hour += 1;
    Status = VRT->SetWakeupTime (
                    TRUE,
                    &Time
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
    
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid72,
      "RT.SetWakeupTime - Set Wakeup time in 1 hour later from now on, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );
    
    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.SetWakeupTime = 1;
    SetVariableRecord(&TestPoint);        
  }
  
  //
  // Get the current wakeup alarm clock setting.
  //
  if (ConfigData->BitMap.GetWakeupTime) {
    Port80(0x81);  
    Status = VRT->GetWakeupTime (
                    &Enable,
                    &Pending,
                    &Time
                    );

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
 
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid81,
      "RT.GetWakeupTime - Get the current wakeup alarm clock setting information, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );
    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.GetWakeupTime = 1;
    SetVariableRecord(&TestPoint);        
  }
}

VOID
EfiCapsuleTestVirtual (
  CONF_INFO  *ConfigData
  )
/*++

Routine Description:

  Test capsule related Runtime Service in runtime phase.

Arguments:
   
   NONE
   
Returns:

   NONE
--*/   
{
  CAPSULE_IMAGE         Capsule1;
  CAPSULE_IMAGE         Capsule2;
  EFI_STATUS            Status;
  TEST_RECORD           TestPoint;
  
  EFI_RESET_TYPE        ResetType;
  EFI_CAPSULE_HEADER   *CapsuleHeaderArray[2]; 
  EFI_GUID              CapsuleGuid = TEST_CAPSULE_GUID;
  EFI_TEST_ASSERTION    AssertionType = EFI_TEST_ASSERTION_FAILED;
  
  //
  // Construct two fake Capsule image.
  // 
  Capsule1.CapsuleHeader.CapsuleGuid        = CapsuleGuid;
  Capsule1.CapsuleHeader.HeaderSize         = sizeof(EFI_CAPSULE_HEADER);
  Capsule1.CapsuleHeader.Flags              = 0;
  Capsule1.CapsuleHeader.CapsuleImageSize   = sizeof(CAPSULE_IMAGE);
  
  Capsule2.CapsuleHeader.CapsuleGuid        = CapsuleGuid;
  Capsule2.CapsuleHeader.HeaderSize         = sizeof(EFI_CAPSULE_HEADER);
  Capsule2.CapsuleHeader.Flags              = 0;
  Capsule2.CapsuleHeader.CapsuleImageSize   = sizeof(CAPSULE_IMAGE);
  
  
  CapsuleHeaderArray[0] = (EFI_CAPSULE_HEADER*)&Capsule1;
  CapsuleHeaderArray[1] = (EFI_CAPSULE_HEADER*)&Capsule2;
  
  //
  // QueryCapsuleCapabilities Test
  //
  if (ConfigData->BitMap.QueryCapsule) {
    Port80(0x91);   
    Status = VRT->QueryCapsuleCapabilities (
                    CapsuleHeaderArray,
                    2,
                    NULL,
                    &ResetType
                    );

    if (EFI_INVALID_PARAMETER == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;

    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuid91,
      "RT.QueryCapsuleCapabilities - Query the capsule capabilities an NULL MaxCapsuleSize, should be EFI_INVALID_PARAMETER",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_INVALID_PARAMETER
      );

    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.QueryCapsule = 1;
    SetVariableRecord(&TestPoint);            
  }

  //
  // UpdateCapsule Test
  // Since UpdateCapsule relates to platform defult behavior,
  // here disable it for common test.
  //
  if (ConfigData->BitMap.UpdateCapsule) {
    Port80(0xA1);    	
    Status = VRT->UpdateCapsule (
                    CapsuleHeaderArray,
                    0,
                    (EFI_PHYSICAL_ADDRESS)NULL
                    );

    if (EFI_INVALID_PARAMETER == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
    
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuidA1,
      "RT.QueryCapsuleCapabilities - Update the capsuls with CapsuleCount 0, should be EFI_INVALID_PARAMETER",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_INVALID_PARAMETER
      );  

    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.UpdateCapsule = 1;
    SetVariableRecord(&TestPoint);            
  }
}


VOID
EfiMiscTestVirtual (
  CONF_INFO  *ConfigData
  )
/*++

Routine Description:

  Test GetNextHighMonotonicCount Runtime Service in runtime phase.

Arguments:
   
   NONE
   
Returns:

   NONE
--*/   
{

  UINT32                Count1;
  EFI_STATUS            Status;
  TEST_RECORD           TestPoint;
  EFI_TEST_ASSERTION    AssertionType = EFI_TEST_ASSERTION_FAILED;

  Count1 = 0;
  Status = EFI_SUCCESS;

  if (ConfigData->BitMap.GetNextCount) {
    Port80(0xB1);  
    //
    // Call GetNextHighMonotonicCount firstly to get the next high 32 bits of the 
    // platform��s monotonic counter.
    //    
    Status = VRT->GetNextHighMonotonicCount(&Count1);

    if (EFI_SUCCESS == Status) 
      AssertionType = EFI_TEST_ASSERTION_PASSED;
    else
      AssertionType = EFI_TEST_ASSERTION_FAILED;
    
    RecordAssertion (
      AssertionType,
      gSCRTAssertionGuidB1,
      "RT.GetNextHighMonotonicCount - First Get next high monotonic counter, should be EFI_SUCCESS",
      "%a:%d:Status - %r, Expected - %r",
      __FILE__,
      __LINE__,
      Status,
      EFI_SUCCESS
      );

    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.GetNextCount = 1;
    SetVariableRecord(&TestPoint);            
  }
}


VOID
EfiResetTestVirtual (
  CONF_INFO  *ConfigData
  )
/*++

Routine Description:

  Test Reset related Runtime Service in runtime phase.

Arguments:
   
   NONE
   
Returns:

   NONE
--*/   
{
  TEST_RECORD    TestPoint;
  
  if (ConfigData->BitMap.ColdReset) {

    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.ColdReset = 1;
    SetVariableRecord(&TestPoint);              
    Port80(0xC1);
    Printf ("RT.ResetSystem - Machine should Cold Reset!");
    //
    // Call shutdown to complete the test.
    //
    VRT->ResetSystem (EfiResetCold, EFI_SUCCESS, 0, NULL);
    //
    // Never Should Be Here.
    //

    RecordAssertion (
      EFI_TEST_ASSERTION_FAILED,
      gSCRTAssertionGuidC1,
      "RT.ResetSystem - Machine should Cold Reset! We should never come here",
      "%a:%d\n",
      __FILE__,
      __LINE__
      );
  }

  if (ConfigData->BitMap.WarmReset) {

    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.WarmReset = 1;
    SetVariableRecord(&TestPoint);              
    Port80(0xC2);
    Printf ("RT.ResetSystem - Machine should Warm Reset!");
    //
    // Call shutdown to complete the test.
    //
    VRT->ResetSystem (EfiResetWarm, EFI_SUCCESS, 0, NULL);
    //
    // Never Should Be Here.
    //
  
    RecordAssertion (
      EFI_TEST_ASSERTION_FAILED,
      gSCRTAssertionGuidC2,
      "RT.ResetSystem - Machine should Warm Reset! We should never come here",
      "%a:%d\n",
      __FILE__,
      __LINE__
      );
  }

  if (ConfigData->BitMap.ShutDown) {

    //
    // Record this step result.
    //
    MemZero(&TestPoint,sizeof(TEST_RECORD));
    TestPoint.Result.BitMap.ShutDown = 1;
    SetVariableRecord(&TestPoint);              
    Port80(0xC3); 
    Printf ("RT.ResetSystem - Machine should Shutdown!");
    //
    // Call shutdown to complete the test.
    //
    VRT->ResetSystem (EfiResetShutdown, EFI_SUCCESS, 0, NULL);
    //
    // Never Should Be Here.
    //
 
    RecordAssertion (
      EFI_TEST_ASSERTION_FAILED,
      gSCRTAssertionGuidC3,
      "RT.ResetSystem - Machine should Shut down! We should never come here",
      "%a:%d\n",
      __FILE__,
      __LINE__
      );
  }
}
