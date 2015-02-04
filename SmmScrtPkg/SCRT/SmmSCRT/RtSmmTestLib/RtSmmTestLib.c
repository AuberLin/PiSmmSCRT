/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. 

Module Name:

  RtSmmTestLib.c

Abstract:

  SMM common test library.

--*/

#include "RtSmmTestLib.h"
#include "SmmCommunication.h"
#include "SCRTDriver.h"
#include "SmmControl2.h"
#include "RtSmmTestLibInternal.h"

EFI_GUID  gSmmCommunicateProtocolAddressGuid = SMM_COMMUNICATE_PROTOCOL_ADDRESS_GUID;

CHAR16  *gSmmCommunicationProtocolVarName             = L"SmmCommuProtoAddressVar";
CHAR16  *gSmmCommunicationBufferVarName             = L"SmmCommuBufAddressVar";
CHAR16  *gSmmControl2ProtocolVarName             = L"SmmControl2ProtoAddressVar";
CHAR16  *gSmmCommunicationAcpiTableAddressVarName             = L"SmmCommuAcpiTableAddressVar";

EFI_GUID gSmmTestGenericFailureGuid = SMM_TEST_GENERIC_FAILURE_GUID;
EFI_GUID gSmmTestNullGuid = SMM_TEST_NULL_GUID;


//
// Global variables
//
VOID* CommunicationBuffer = NULL;
//
// Number of test assertions in one test smm handler.
//
UINTN NumOfAssertions = 0;

EFI_STATUS
EFIAPI
PrepareCommunicationBuffer (
  IN  EFI_GUID                  *TestHandlerGuid
  )
{
  EFI_SMM_COMMUNICATE_HEADER  *CommHeader;
  
  if (CommunicationBuffer == NULL) {
  	return EFI_INVALID_PARAMETER;
  }
  //
  // Init communicate buffer to zero.
  //
  SmmTestSetMem (CommunicationBuffer, MAX_COMMUNICATION_BUFFER_SIZE, 0);

  CommHeader = (EFI_SMM_COMMUNICATE_HEADER*) CommunicationBuffer;
  CommHeader->MessageLength = MAX_COMMUNICATION_BUFFER_SIZE - sizeof (EFI_SMM_COMMUNICATE_HEADER);
  
  //
  // Specify which test handler will be triggered.
  //
  SmmTestCopyMem (&CommHeader->HeaderGuid, TestHandlerGuid, sizeof(EFI_GUID));

  return EFI_SUCCESS;
}
/*++

Routine Description:

  

Returns:

  EFI_SUCCESS if everything ok.

--*/
EFI_STATUS
EFIAPI
InvokeTestSmiHandler (
  IN  EFI_RUNTIME_SERVICES  *vRT,
  IN  EFI_GUID                  *TestHandlerGuid,
  IN  SMM_BB_TEST_ASSERTION_DESCRIPTION *AssertionArray  
  )
{
  EFI_STATUS Status;
  EFI_SMM_COMMUNICATION_PROTOCOL   *SmmComm;
  EFI_PHYSICAL_ADDRESS  Address;
  UINTN  CommBufSize;

  NumOfAssertions = 0;
  while (SmmTestCompareGuid(&AssertionArray->AssertionId, &gSmmTestNullGuid) != 0) {
    NumOfAssertions++;
    AssertionArray ++;
  }
  if (NumOfAssertions > ((MAX_COMMUNICATION_BUFFER_SIZE - sizeof (EFI_SMM_COMMUNICATE_HEADER))/sizeof(SMM_BB_TEST_RESULT))) {
    return EFI_BUFFER_TOO_SMALL;
  }

  CommBufSize = sizeof (EFI_PHYSICAL_ADDRESS);
  Status = vRT->GetVariable (
                    gSmmCommunicationBufferVarName,                   
                    &gSmmCommunicateProtocolAddressGuid,          
                    NULL,                       
                    &CommBufSize,                  
                    &Address                    
                    );
  if (EFI_ERROR(Status)) {
    return Status;
  }
  //Convert communication buffer to virtual address to initialize its contents.                  
  Address = PhysicalToVirtual ((UINTN) Address);
  CommunicationBuffer = (VOID*)(UINTN)Address;
                    
  Status = PrepareCommunicationBuffer (TestHandlerGuid);
  if (EFI_ERROR(Status)) {
    return EFI_INVALID_PARAMETER;
  }

  CommBufSize = sizeof (EFI_PHYSICAL_ADDRESS);
  Status = vRT->GetVariable (
                    gSmmCommunicationProtocolVarName,                   
                    &gSmmCommunicateProtocolAddressGuid,          
                    NULL,                       
                    &CommBufSize,                  
                    &Address                    
                    );  

  if (EFI_ERROR(Status)) {
    return Status;
  }
  Address = PhysicalToVirtual ((UINTN) Address);
  SmmComm = (EFI_SMM_COMMUNICATION_PROTOCOL *)(UINTN)Address;
  //Revert Communication buffer to physical address to meet param requirement.
  Address = (UINTN)CommunicationBuffer;
  Address = VirtualToPhysical ((UINTN) Address);
  CommunicationBuffer = (VOID*)(UINTN)Address;
  
  CommBufSize = MAX_COMMUNICATION_BUFFER_SIZE;
  Status = SmmComm->Communicate(SmmComm, CommunicationBuffer, &CommBufSize);
  if (EFI_ERROR(Status)) {
    return EFI_NOT_STARTED;
  }

  //Convert communication buffer to virtual address again for later test use.  
  Address = (UINTN)CommunicationBuffer;
  Address = PhysicalToVirtual ((UINTN) Address);
  CommunicationBuffer = (VOID*)(UINTN)Address;
  
  return EFI_SUCCESS;
  
}

/*++

Routine Description:

  

Returns:

  EFI_SUCCESS if everything is correct.

--*/
EFI_STATUS
EFIAPI
CheckSmmTestResult (
  
  IN  SMM_BB_TEST_ASSERTION_DESCRIPTION *AssertionArray
  )
{
  
  SMM_BB_TEST_RESULT  *ResultRecord;
  UINTN  i;
  SMM_BB_TEST_ASSERTION_DESCRIPTION*  AssertDescRecord;
  BOOLEAN  DescFound;
  
  if (CommunicationBuffer == NULL) {
    return EFI_NOT_FOUND;
  }

  ResultRecord = (SMM_BB_TEST_RESULT*) ((UINTN)CommunicationBuffer + sizeof (EFI_SMM_COMMUNICATE_HEADER));

  for (i = 0; i < NumOfAssertions; i++) {
    AssertDescRecord = AssertionArray;
    DescFound = FALSE;
    while (SmmTestCompareGuid (&AssertDescRecord->AssertionId, &gSmmTestNullGuid) != 0) {
      if (SmmTestCompareGuid (&AssertDescRecord->AssertionId, &ResultRecord[i].AssertionId) == 0) {
        DescFound = TRUE;
	    break;
      }

      AssertDescRecord ++;
    }

    if (DescFound) {
      //
      // Workaround for SCRT limitation
      //
      if (ResultRecord[i].Result == EFI_TEST_ASSERTION_WARNING) {
        ResultRecord[i].Result = EFI_TEST_ASSERTION_PASSED;
	  }
 
      if (ResultRecord[i].Result == EFI_TEST_ASSERTION_PASSED) {
        NumOfPass++;
      }
      else {
        NumOfFail++;
      }
     
	  RecordAssertion (
                   ResultRecord[i].Result,
                   ResultRecord[i].AssertionId,
                   AssertDescRecord->Description,
                   "Result record from test handler line: %d; TestContext : 0x%lx",
                   ResultRecord[i].LineNumber,
                   ResultRecord[i].Handle
                   );
    }
    else {
      if (SmmTestCompareGuid (&AssertDescRecord->AssertionId, &gSmmTestNullGuid) != 0) {
        NumOfFail++;
	    RecordAssertion (
                   EFI_TEST_ASSERTION_WARNING,
                   ResultRecord[i].AssertionId,
                   "No description found for test assertion",
                   "Assertion GUID:%g: Test Result - %d; TestContext : 0x%lx",
                   &ResultRecord[i].AssertionId,
                   ResultRecord[i].Result, 
                   ResultRecord[i].Handle
                   );
      }
    }
  }

  return EFI_SUCCESS;

}

EFI_STATUS
EFIAPI
InvokeTestSmiHandlerViaAcpiTable (
  IN  EFI_RUNTIME_SERVICES  *vRT,
  IN  EFI_GUID                  *TestHandlerGuid,
  IN  SMM_BB_TEST_ASSERTION_DESCRIPTION *AssertionArray  
  )
{
  EFI_STATUS Status;
  EFI_SMM_CONTROL2_PROTOCOL   *SmmControl2;
  EFI_PHYSICAL_ADDRESS  Address;
  
  EFI_SMM_COMMUNICATION_ACPI_TABLE *SmmCommunicationAcpiTable;
  EFI_PHYSICAL_ADDRESS  SmmCommunicationAcpiTableAddress;
  UINT8                            SmiCommand;
  UINTN                            Size;

  NumOfAssertions = 0;
  while (SmmTestCompareGuid(&AssertionArray->AssertionId, &gSmmTestNullGuid) != 0) {
    NumOfAssertions++;
    AssertionArray ++;
  }
  if (NumOfAssertions > ((MAX_COMMUNICATION_BUFFER_SIZE - sizeof (EFI_SMM_COMMUNICATE_HEADER))/sizeof(SMM_BB_TEST_RESULT))) {
    return EFI_BUFFER_TOO_SMALL;
  }

  Size = sizeof (EFI_PHYSICAL_ADDRESS);
  Status = vRT->GetVariable (
                    gSmmCommunicationBufferVarName,                   
                    &gSmmCommunicateProtocolAddressGuid,          
                    NULL,                       
                    &Size,                  
                    &Address                    
                    );
  if (EFI_ERROR(Status)) {
    return Status;
  }
  //Convert communication buffer to virtual address to initialize its contents.                  
  Address = PhysicalToVirtual ((UINTN) Address);
  CommunicationBuffer = (VOID*)(UINTN)Address;
                    
  Status = PrepareCommunicationBuffer (TestHandlerGuid);
  if (EFI_ERROR(Status)) {
    return EFI_ABORTED;
  }

  Size = sizeof (EFI_PHYSICAL_ADDRESS);
  Status = vRT->GetVariable (
                    gSmmControl2ProtocolVarName,                   
                    &gSmmCommunicateProtocolAddressGuid,          
                    NULL,                       
                    &Size,                  
                    &Address                    
                    );  

  if (EFI_ERROR(Status)) {
    return Status;
  }
  Address = PhysicalToVirtual ((UINTN) Address);
  SmmControl2 = (EFI_SMM_CONTROL2_PROTOCOL *)(UINTN)Address;
  
  
  // Get ACPI table address
  Size = sizeof (SmmCommunicationAcpiTableAddress);
  Status = vRT->GetVariable (
                    gSmmCommunicationAcpiTableAddressVarName,                   
                    &gSmmCommunicateProtocolAddressGuid,          
                    NULL,                       
                    &Size,                  
                    &SmmCommunicationAcpiTableAddress                    
                    );  

  if (EFI_ERROR(Status)) {
    return Status;
  }
  SmmCommunicationAcpiTable = (EFI_SMM_COMMUNICATION_ACPI_TABLE *)(UINTN)SmmCommunicationAcpiTableAddress;

  //Revert Communication buffer to physical address to meet ACPI table filling requirement.
  Address = (UINTN)CommunicationBuffer;
  Address = VirtualToPhysical ((UINTN) Address);
  CommunicationBuffer = (VOID*)(UINTN)Address;

  //Convert ACPI table to virtual address to fill in communicate buffer address.                  
  SmmCommunicationAcpiTable = (EFI_SMM_COMMUNICATION_ACPI_TABLE *) PhysicalToVirtual ((UINTN) SmmCommunicationAcpiTable);
  SmmCommunicationAcpiTable->BufferPtrAddress = (EFI_PHYSICAL_ADDRESS)(UINTN)CommunicationBuffer;
  
  //
  // Send command
  //
  SmiCommand = (UINT8)SmmCommunicationAcpiTable->SwSmiNumber;
  
  Status = SmmControl2->Trigger (
                         SmmControl2,
                         (INT8 *)&SmiCommand,
                         NULL,
                         FALSE,
                         0
                         );
  if (EFI_ERROR(Status)) {
    return EFI_ABORTED;
  }

  //Convert communication buffer to virtual address again for other test framework components use.  
  Address = (UINTN)CommunicationBuffer;
  Address = PhysicalToVirtual ((UINTN) Address);
  CommunicationBuffer = (VOID*)(UINTN)Address;
  
  return EFI_SUCCESS;
  
}


/*++

Routine Description:

  

Returns:

  EFI_SUCCESS if everything is correct.

--*/
EFI_STATUS
EFIAPI
RecordSmmTestAssertion (
  IN EFI_HANDLE             TestContext OPTIONAL,
  IN  EFI_GUID                  *AssertionGuid,
  IN  UINT32  Result,
  IN  UINT32     AtLine,
  IN  SMM_BB_TEST_RESULT* ResultArray,
  IN  UINTN        ResultBufferSize
  )
{
  UINTN i;
  UINTN NumOfResultEntry;
  
  NumOfResultEntry = ResultBufferSize/sizeof(SMM_BB_TEST_RESULT);
  for (i = 0; i < NumOfResultEntry; i++) {
    if (SmmTestCompareGuid(&ResultArray[i].AssertionId, &gSmmTestNullGuid) == 0) {
      /*run in SMM, so not use gtBS*/
      SmmTestCopyMem (&ResultArray[i].AssertionId, AssertionGuid, sizeof(EFI_GUID));
      ResultArray[i].LineNumber = AtLine;
      ResultArray[i].Result = Result;
      if (TestContext != NULL) {
        ResultArray[i].Handle = (UINT64)(UINTN)TestContext;
      }
      break;
    }
  }
  
  return EFI_SUCCESS;
}

VOID
SmmTestCopyMem (
  IN VOID     *Dest,
  IN VOID     *Src,
  IN UINTN    len
  )
/*++

Routine Description:
  Copies the contents of one buffer to another.

Arguments:
  Dest                - A pointer to the buffer to copy to

  Src                 - A pointer to the buffer to copy from.

  len                 - The number of bytes to copy.

Returns:

  None

--*/
{
  CHAR8    *d, *s;

  d = Dest;
  s = Src;
  while (len--) {
    *(d++) = *(s++);
  }
}

VOID
SmmTestSetMem (
  IN VOID                           *Buffer,
  IN UINTN                          len,
  IN UINT8                         Value
  )
{
  INT8* Ptr;

  Ptr = Buffer;
  while(len--) {
    *Ptr++ = Value;
  }
}

INTN
SmmTestCompareGuid(
  IN EFI_GUID     *Guid1,
  IN EFI_GUID     *Guid2
  )
/*++

Routine Description:

  Compares to GUIDs

Arguments:

  Guid1       - guid to compare
  Guid2       - guid to compare

Returns:
  = 0     if Guid1 == Guid2

--*/
{
  INT32       *g1, *g2, r;

  //
  // Compare 32 bits at a time
  //

  g1 = (INT32 *) Guid1;
  g2 = (INT32 *) Guid2;

  r  = g1[0] - g2[0];
  r |= g1[1] - g2[1];
  r |= g1[2] - g2[2];
  r |= g1[3] - g2[3];

  return r;
}

BOOLEAN
SmmGrowBuffer(
  IN EFI_SMM_SYSTEM_TABLE *Smst,
  IN OUT EFI_STATUS   *Status,
  IN OUT VOID         **Buffer,
  IN UINTN            BufferSize
  )
/*++

Routine Description:

    Helper function called as part of the code needed
    to allocate the proper sized buffer for various
    EFI interfaces.

Arguments:

    Status      - Current status

    Buffer      - Current allocated buffer, or NULL

    BufferSize  - Current buffer size needed

Returns:

    TRUE - if the buffer was reallocated and the caller
    should try the API again.

--*/
{
  BOOLEAN         TryAgain;

  //
  // If this is an initial request, buffer will be null with a new buffer size
  //

  if (!*Buffer && BufferSize) {
    *Status = EFI_BUFFER_TOO_SMALL;
  }

  //
  // If the status code is "buffer too small", resize the buffer
  //

  TryAgain = FALSE;
  if (*Status == EFI_BUFFER_TOO_SMALL) {

    if (*Buffer) {
      Smst->SmmFreePool (*Buffer);
    }

    (*Status) = Smst->SmmAllocatePool (
                      EfiRuntimeServicesData,
                      BufferSize,
                      Buffer
                      );
    if (EFI_ERROR(*Status)) {
      *Status = EFI_OUT_OF_RESOURCES;
    }

    if (*Buffer) {
      TryAgain = TRUE;
    } else {
      *Status = EFI_OUT_OF_RESOURCES;
    }
  }

  //
  // If there's an error, free the buffer
  //

  if (!TryAgain && EFI_ERROR(*Status) && *Buffer) {
    Smst->SmmFreePool (*Buffer);
    *Buffer = NULL;
  }

  return TryAgain;
}

EFI_STATUS
SmmLibLocateHandle (
  IN EFI_SMM_SYSTEM_TABLE         *Smst,
  IN EFI_LOCATE_SEARCH_TYPE       SearchType,
  IN EFI_GUID                     *Protocol OPTIONAL,
  IN VOID                         *SearchKey OPTIONAL,
  IN OUT UINTN                    *NoHandles,
  OUT EFI_HANDLE                  **Buffer
  )
/*++

Routine Description:

  Function returns an array of handles that support the requested protocol
  in a buffer allocated from pool.

Arguments:

  SearchType           - Specifies which handle(s) are to be returned.
  Protocol             - Provides the protocol to search by.
                         This parameter is only valid for SearchType ByProtocol.
  SearchKey            - Supplies the search key depending on the SearchType.
  NoHandles            - The number of handles returned in Buffer.
  Buffer               - A pointer to the buffer to return the requested array of
                         handles that support Protocol.

Returns:

  EFI_SUCCESS           - The result array of handles was returned.
  EFI_NOT_FOUND         - No handles match the search.
  EFI_OUT_OF_RESOURCES - There is not enough pool memory to store the matching results.

--*/
{
  EFI_STATUS          Status;
  UINTN               BufferSize;

  //
  // Initialize for GrowBuffer loop
  //

  Status = EFI_SUCCESS;
  *Buffer = NULL;
  BufferSize = 50 * sizeof(EFI_HANDLE);

  //
  // Call the real function
  //

  while (SmmGrowBuffer (Smst, &Status, (VOID **) Buffer, BufferSize)) {
    Status = Smst->SmmLocateHandle (
                     SearchType,
                     Protocol,
                     SearchKey,
                     &BufferSize,
                     *Buffer
                     );
  }

  *NoHandles = BufferSize / sizeof (EFI_HANDLE);
  if (EFI_ERROR(Status)) {
    *NoHandles = 0;
  }

  return Status;
}

