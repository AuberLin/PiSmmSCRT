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

  ParseConf.c

--*/

#include "ParseConf.h"


STATIC
VOID *
memset (
  OUT VOID    *Dest,
  IN  UINTN   Char,
  IN  UINTN   Count
  )
/*++

Routine Description:
  
  Sets buffers to a specified character.
  
Arguments: 
  
  Dest      - Pointer to destination.
  Char      - Character to set. 
  Count     - Number of characters. 
  
Returns:

  Return the value of Dest.

--*/  
{
  volatile UINT8  *Ptr;
  
  for (Ptr = Dest; Count > 0; Count--, Ptr++) {
    *Ptr = (UINT8) Char;
  }

  return Dest;
}


STATIC
VOID *
memcpy (
  OUT VOID        *Dest,
  IN  const VOID  *Src,
  IN  UINTN       Count
  )
/*++

Routine Description:
  
  Copies characters between buffers.
  
Arguments: 
  
  Dest    -  New buffer. 
  Src     -  Buffer to copy from. 
  Count   -  Number of characters to copy. 
  
Returns:

  Return the value of Dest.
  
--*/    
{
  volatile UINT8  *Ptr;
  const    UINT8  *Source;
  
  for (Ptr = Dest, Source = Src; Count > 0; Count--, Source++, Ptr++) {
    *Ptr = *Source;
  }
  return Dest;
}


STATIC
UINT32
strlen (
  UINT8 *string
  )
/*++

Routine Description:
  
  Get the length of a string.
  
Arguments: 
  
  String   -  Null-terminated string. 
  
Returns:

  Returns the number of characters in string.

--*/    
{
  UINT32  count;

  count = 0;
  while (string[count] != '\0') {
    count++;
  }
  return count;
}


STATIC
CHAR8 *
EFIAPI
AsciiStrtok(
  IN CHAR8     *s,
  IN CHAR8     *delim
  )
/*++

Routine Description:
  
  Find the next token in a string.
  
Arguments: 
  
  s      - String containing token(s). 
  delim  - Set of delimiter characters. 
  
Returns:

   Return a pointer to the next token found in strToken.

--*/    
{
  CHAR8 *spanp;
  UINTN c, sc;
  CHAR8 *tok;
  static char *last;
  
  if (s == NULL && (s = last) == NULL) {
    return (NULL);
  }       
                
cont:
    
  c = *s++;
  for (spanp = (char *)delim; (sc = *spanp++) != 0;) {
    if (c == sc) {
      goto cont;
    } 
  }
  
  if (c == 0) {
    last = NULL;
    return (NULL);
  }
  tok = s - 1;
  
  for (; ;) {
    c = *s++;
    spanp = (char *)delim;
    do {
      if ((sc = *spanp++) == c) {
        if (c == 0) {
          s = NULL;
        } else {
          s[-1] = 0;
        }
        last = s;
        return (tok);
      }
    } while (sc != 0);
  }
}


STATIC
CHAR8*
EFIAPI    
AsciiStrChr (
  IN  CHAR8  *String,
  IN  CHAR8  c
  )
/*++

Routine Description:
  
  Find a character in a string.
  
Arguments: 
  
  String      - Null-terminated source string. .
  c           - Character to be located. 
  
Returns:

  Returns a pointer to the first occurrence of c in string.
  
--*/    
{
  while (*String != '\0') {
    if (*String == c) {
      return String;
    }
    String ++;
  }
  return NULL;
}


STATIC
CHAR8*
EFIAPI    
AsciiStrStr (
  IN  CHAR8  *String,
  IN  CHAR8  *StrCharSet
  )
/*++

Routine Description:
  
  Find a Ascii substring.
  
Arguments: 
  
  String      - Null-terminated Ascii string to search.
  StrCharSet  - Null-terminated Ascii string to search for.
  
Returns:

  The address of the first occurrence of the matching Ascii substring if successful, or NULL otherwise.

--*/
{
  CHAR8 *Src;
  CHAR8 *Sub;
   
  Src = String;
  Sub = StrCharSet;
  
  while ((*String != '\0') && (*StrCharSet != '\0')) {
    if (*String++ != *StrCharSet++) {
      String = ++Src;
      StrCharSet = Sub;
    }
  }
  if (*StrCharSet == '\0') {
    return Src;
  } else {
    return NULL;
  }
}


STATIC
INTN
EFIAPI
AsciiStrCmp (
  IN  CHAR8     *FirstString,
  IN  CHAR8     *SecondString
  )
/*++

Routine Description:
  
  Compares two Null-terminated ASCII strings, and returns the difference
  between the first mismatched ASCII characters.  
  
Arguments: 
  
  FirstString  - Pointer to a Null-terminated ASCII string.
  SecondString - Pointer to a Null-terminated ASCII string.
  
Returns:

  0      FirstString is identical to SecondString..
  !=0    FirstString is not identical to SecondString.

--*/    
{
  while ((*FirstString != '\0') && (*FirstString == *SecondString)) {
    FirstString++;
    SecondString++;
  }
  return *FirstString - *SecondString;
}


INTN
EFIAPI
UnicodeStrCmp (
  IN  CHAR16     *FirstString,
  IN  CHAR16     *SecondString
  )
/*++

Routine Description:
  
  Compares two Null-terminated Unicode strings, and returns the difference
  between the first mismatched Unicode characters.  
  
Arguments: 
  
  FirstString  - Pointer to a Null-terminated Unicode string.
  SecondString - Pointer to a Null-terminated Unicode string.
  
Returns:

  0      FirstString is identical to SecondString..
  !=0    FirstString is not identical to SecondString.

--*/    
{
  while ((*FirstString != L'\0') && (*FirstString == *SecondString)) {
    FirstString++;
    SecondString++;
  }
  return *FirstString - *SecondString;
}


STATIC
CHAR8 *
EFIAPI
AsciiStrCpy (
  IN   CHAR8    *Destination,
  IN   CHAR8    *Source
  )
/*++

Routine Description:
  
  Copies one Null-terminated ASCII string to another Null-terminated ASCII
  string and returns the new ASCII string.
  
Arguments: 
  
  Destination - Pointer to a Null-terminated ASCII string.
  Source      - Pointer to a Null-terminated ASCII string.
  
Returns:

  return Destination

--*/   
{
  CHAR8    *ReturnValue;

  ReturnValue = Destination;
  while (*Source) {
    *(Destination++) = *(Source++);
  }
  *Destination = 0;
  return ReturnValue;
}


VOID
EFIAPI
UnicodeStrCpy (
  IN   CHAR16       *Destination,
  IN   CHAR16       *Source
  )
/*++

Routine Description:
  
  Copies one Null-terminated unicode string to another Null-terminated unicode
  string and returns the new unicode string.
  
Arguments: 
  
  Destination - Pointer to a Null-terminated unicode string.
  Source      - Pointer to a Null-terminated unicode string.
  
Returns:

  NONE

--*/   
{
  while (*Source) {
    *(Destination++) = *(Source++);
  }
  *Destination = 0;
}



STATIC
CHAR8 *
AsciiReadLine (
  IN MEMORY_FILE    *InputFile,
  IN OUT CHAR8      *InputBuffer,
  IN UINTN          MaxLength
  )
/*++

Routine Description:

  This function reads a line, stripping any comments.
  The function reads a string from the input stream argument and stores it in 
  the input string. ReadLine reads characters from the current file position 
  to and including the first newline character, to the end of the stream, or 
  until the number of characters read is equal to MaxLength - 1, whichever 
  comes first.  The newline character, if read, is replaced with a \0. 

Arguments:

  InputFile   -  Memory file image.
  InputBuffer -  Buffer to read into, must be _MAX_PATH size.
  MaxLength   -  The maximum size of the input buffer.

Returns:

   NULL          if error or EOF

--*/
{
  CHAR8 *CharPtr;
  CHAR8 *EndOfLine;
  UINTN CharsToCopy;


  //
  // Check for end of file condition
  //
  if (InputFile->CurrentFilePointer >= InputFile->Eof) {
    return NULL;
  }
  //
  // Find the next newline char
  //
  EndOfLine = AsciiStrChr (InputFile->CurrentFilePointer, '\n');

  //
  // Determine the number of characters to copy.
  //
  if (EndOfLine == 0) {
    //
    // If no newline found, copy to the end of the file.
    //
    CharsToCopy = InputFile->Eof - InputFile->CurrentFilePointer;
  } else if (EndOfLine >= InputFile->Eof) {
    //
    // If the newline found was beyond the end of file, copy to the eof.
    //
    CharsToCopy = InputFile->Eof - InputFile->CurrentFilePointer;
  } else {
    //
    // Newline found in the file.
    //
    CharsToCopy = EndOfLine - InputFile->CurrentFilePointer;
  }
  //
  // If the end of line is too big for the current buffer, set it to the max
  // size of the buffer (leaving room for the \0.
  //
  if (CharsToCopy > MaxLength - 1) {
    CharsToCopy = MaxLength - 1;
  }
  //
  // Copy the line.
  //
  memcpy (InputBuffer, InputFile->CurrentFilePointer, CharsToCopy);

  if (EndOfLine == 0) {
  //
  // Meet EoF without a line break, copy till end of file.
  //
    InputBuffer[CharsToCopy] = '\0';
  }
  else {
  //
  // Add the null termination over the 0x0D
  //
  InputBuffer[CharsToCopy - 1] = '\0';
  }
  //
  // Increment the current file pointer (include the 0x0A)
  //
  InputFile->CurrentFilePointer += CharsToCopy + 1;

  //
  // Strip any comments
  //
  CharPtr = AsciiStrStr (InputBuffer, "//");
  if (CharPtr != 0) {
    CharPtr[0] = 0;
  }
  //
  // Return the string
  //
  return InputBuffer;
}


STATIC
BOOLEAN
AsciiFindSection (
  IN MEMORY_FILE    *InputFile,
  IN CHAR8          *Section
  )
/*++

Routine Description:

  This function parses a file from the beginning to find a section.
  The section string may be anywhere within a line.

Arguments:

  InputFile  -   Memory file image.
  Section    -   Section to search for

Returns:

  FALSE if error or EOF
  TRUE if section found

--*/
{
  CHAR8 InputBuffer[_MAX_PATH];
  CHAR8 *CurrentToken;

  //
  // Rewind to beginning of file
  //
  InputFile->CurrentFilePointer = InputFile->FileImage;

  //
  // Read lines until the section is found
  //
  while (InputFile->CurrentFilePointer < InputFile->Eof) {
    //
    // Read a line
    //
    AsciiReadLine (InputFile, InputBuffer, _MAX_PATH);

    //
    // Check if the section is found
    //
    CurrentToken = AsciiStrStr (InputBuffer, Section);
    if (CurrentToken != NULL) {
      return TRUE;
    }
  }

  return FALSE;
}



STATIC
EFI_STATUS
AsciiFindToken (
  IN MEMORY_FILE    *InputFile,
  IN CHAR8          *Section,
  IN CHAR8          *Token,
  IN UINTN          Instance,
  OUT CHAR8         *Value
  )
/*++

Routine Description:

  Finds a token value given the section and token to search for.

Arguments:

  InputFile  -  Memory file image.
  Section    -  The section to search for, a string within [].
  Token      -  The token to search for, e.g. EFI_PEIM_RECOVERY, followed by an = in the INF file.
  Instance   -  The instance of the token to search for.  Zero is the first instance.
  Value      -  The string that holds the value following the =.  Must be _MAX_PATH in size.

Returns:

  EFI_SUCCESS             Value found.
  EFI_ABORTED             Format error detected in INF file.
  EFI_INVALID_PARAMETER   Input argument was null.
  EFI_LOAD_ERROR          Error reading from the file.
  EFI_NOT_FOUND           Section/Token/Value not found.

--*/
{
  CHAR8   InputBuffer[_MAX_PATH];
  CHAR8   *CurrentToken;
  BOOLEAN ParseError;
  BOOLEAN ReadError;
  UINTN   Occurrance;

  //
  // Check input parameters
  //
  if (InputFile->FileImage == NULL ||
      InputFile->Eof == NULL ||
      InputFile->CurrentFilePointer == NULL ||
      Section == NULL ||
      strlen (Section) == 0 ||
      Token == NULL ||
      strlen (Token) == 0 ||
      Value == NULL
      ) {
    return EFI_INVALID_PARAMETER;
  }
  //
  // Initialize error codes
  //
  ParseError  = FALSE;
  ReadError   = FALSE;

  //
  // Initialize our instance counter for the search token
  //
  Occurrance = 0;

  if (AsciiFindSection (InputFile, Section)) {
    //
    // Found the desired section, find and read the desired token
    //
    do {
      //
      // Read a line from the file
      //
      if (AsciiReadLine (InputFile, InputBuffer, _MAX_PATH) == NULL) {
        //
        // Error reading from input file
        //
        ReadError = TRUE;
        break;
      }
      //
      // Get the first non-whitespace string
      //
      CurrentToken = AsciiStrtok (InputBuffer, " \t\n");
      if (CurrentToken == NULL) {
        //
        // Whitespace line found (or comment) so continue
        //
        CurrentToken = InputBuffer;
        continue;
      }
      //
      // Make sure we have not reached the end of the current section
      //
      if (CurrentToken[0] == '[') {
        break;
      }
      //
      // Compare the current token with the desired token
      //
      if (AsciiStrCmp (CurrentToken, Token) == 0) {
        //
        // Found it
        //
        //
        // Check if it is the correct instance
        //
        if (Instance == Occurrance) {
          //
          // Copy the contents following the =
          //
          CurrentToken = AsciiStrtok (NULL, "= \t\n");
          if (CurrentToken == NULL) {
            //
            // Nothing found, parsing error
            //
            ParseError = TRUE;
          } else {
            //
            // Copy the current token to the output value
            //
            AsciiStrCpy (Value, CurrentToken);
            return EFI_SUCCESS;
          }
        } else {
          //
          // Increment the occurrance found
          //
          Occurrance++;
        }
      }
    } while (
      !ParseError &&
      !ReadError &&
      InputFile->CurrentFilePointer < InputFile->Eof &&
      CurrentToken[0] != '[' &&
      Occurrance <= Instance
    );
  }
  //
  // Distinguish between read errors and INF file format errors.
  //
  if (ReadError) {
    return EFI_LOAD_ERROR;
  }

  if (ParseError) {
    return EFI_ABORTED;
  }

  return EFI_NOT_FOUND;
}

UINTN
Ascii_xtoi (
    CHAR8  *str
    )
// convert hex string to uint
{
    UINTN       u;
    CHAR8      c;

    // skip preceeding white space
    while (*str && *str == ' ') {
        str += 1;
    }

    // skip preceeding zeros
    while (*str && *str == '0') {
        str += 1;
    }

    // skip preceeding white space
    if (*str && (*str == 'x' || *str == 'X')) {
        str += 1;
    }

    // convert hex digits
    u = 0;
    c = *(str++);
    while (c) {
        if (c >= 'a'  &&  c <= 'f') {
            c -= 'a' - 'A';
        }

        if ((c >= '0'  &&  c <= '9')  ||  (c >= 'A'  &&  c <= 'F')) {
            u = (u << 4)  |  (c - (c >= 'A' ? 'A'-10 : '0'));
        } else {
            break;
        }
        c = *(str++);
    }

    return u;
}

UINTN
Ascii_Atoi (
    CHAR8  *str
    )
// convert hex string to uint
{
    UINTN       u;
    CHAR8      c;

    // skip preceeding white space
    while (*str && *str == ' ') {
        str += 1;
    }

    // convert digits
    u = 0;
    c = *(str++);
    while (c) {
        if (c >= '0' && c <= '9') {
            u = (u * 10) + c - '0';
        } else {
            break;
        }
        c = *(str++);
    }

    return u;
}

VOID
ParseConf (
  IN MEMORY_FILE  *InfFile,
  IN CONF_INFO    *FileInfo
  )
/*++

Routine Description:

  This function parses a configuration file and copies info into a CONF_INFO structure.

Arguments:

  InfFile    -     Memory file image.
  FileInfo   -     Information read from INF file.
  
Returns:

  NONE
  
--*/
{
  CHAR8       Value[_MAX_PATH];
  EFI_STATUS  Status;

  //
  // Initialize Configuration info
  //
  memset (FileInfo, 0, sizeof (CONF_INFO));

  FileInfo->BitMap.Signature = CONFIGURE_INFO_SIGNATURE;
  //
  // Read the GetVariableString token
  //
  Status = AsciiFindToken (InfFile, VARIABLE_SECTION_STRING, GET_VARIABLE_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.GetVariable = 0x1;
    } 
  }
  
  //
  // Read the SetVariableString token
  //
  Status = AsciiFindToken (InfFile, VARIABLE_SECTION_STRING, SET_VARIABLE_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.SetVariable = 0x1;
    } 
  }


  //
  // Read the GetNextVariableName token
  //
  Status = AsciiFindToken (InfFile, VARIABLE_SECTION_STRING, GET_NEXT_VARIABLE_NAME_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.GetNextVariable = 0x1;
    } 
  }


  //
  // Read the QueryVariableInfo token
  //
  Status = AsciiFindToken (InfFile, VARIABLE_SECTION_STRING, QUERY_VARIABLE_INFO_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.QueryVariable = 0x1;
    } 
  }


  //
  // Read the GetTime token
  //
  Status = AsciiFindToken (InfFile, TIME_SECTION_STRING, GET_TIME_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.GetTime = 0x1;
    } 
  }


  //
  // Read the SetTime token
  //
  Status = AsciiFindToken (InfFile, TIME_SECTION_STRING, SET_TIME_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.SetTime = 0x1;
    } 
  }


  //
  // Read the GetWakeupTime token
  //
  Status = AsciiFindToken (InfFile, TIME_SECTION_STRING, GET_WAKEUP_TIME_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.GetWakeupTime = 0x1;
    } 
  }


  //
  // Read the SetWakeupTime token
  //
  Status = AsciiFindToken (InfFile, TIME_SECTION_STRING, SET_WAKEUP_TIME_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.SetWakeupTime = 0x1;
    } 
  }


  //
  // Read the UpdateCapsule token
  //
  Status = AsciiFindToken (InfFile, CAPSULE_SECTION_STRING, UPDATE_CAPSULE_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.UpdateCapsule  = 0x1;
    } 
  }


  //
  // Read the QueryCapsuleCapabilities token
  //
  Status = AsciiFindToken (InfFile, CAPSULE_SECTION_STRING, QUERY_CAPSULE_CAPABILITIES_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.QueryCapsule = 0x1;
    } 
  }


  //
  // Read the GetNextHighMonotonicCount token
  //
  Status = AsciiFindToken (InfFile, MONOTONICCOUNT_SECTION_STRING, GET_NEXT_HIGH_MONOTONIC_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.GetNextCount = 0x1;
    } 
  }

  //
  // Read the ColdReset token
  //
  Status = AsciiFindToken (InfFile, RESET_SECTION_STRING, COLD_RESET_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.ColdReset = 0x1;
    } 
  }

  //
  // Read the WarmReset token
  //
  Status = AsciiFindToken (InfFile, RESET_SECTION_STRING, WARM_RESET_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.WarmReset = 0x1;
    } 
  }

  //
  // Read the ShutDown token
  //
  Status = AsciiFindToken (InfFile, RESET_SECTION_STRING, SHUT_DOWN_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    //
    // Update attribute
    //
    if (AsciiStrCmp (Value, TRUE_STRING) == 0) {
      FileInfo->BitMap.ShutDown = 0x1;
    } 
  }

}

VOID
GetUARTAddressFromConf (
  IN MEMORY_FILE  *InfFile,
  IN RUNTIME_HANDOFF *HandOffInfo
  )
/*++

Routine Description:

  This function parses a configuration file and copies info into a CONF_INFO structure.

Arguments:

  InfFile    -     Memory file image.
  FileInfo   -     Information read from INF file.
  
Returns:

  NONE
  
--*/
{
  CHAR8       Value[_MAX_PATH];
  EFI_STATUS  Status;
  UINTN  Temp;
  
  //
  // Read the Uart MmioBaseAddress token
  //
  memset (Value, 0, sizeof(Value));
  Status = AsciiFindToken (InfFile, UART_SECTION_STRING, UART_MMIO_BASE_ADDRESS_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    Temp = ASCIISTR_TO_INT(Value);
    //
    // Update attribute
    //
    if (Temp != 0) {
      Print(L"Override with UART MMIO base %x registered in SCRT.conf file.\n", Temp);
      HandOffInfo->DebuggerInfo.MmioFlag = TRUE;
      HandOffInfo->DebuggerInfo.MmioBase = Temp;
    } 
  }

  //
  // Read the Uart IoPortBaseAddress token
  //
  memset (Value, 0, sizeof(Value));
  Status = AsciiFindToken (InfFile, UART_SECTION_STRING, UART_IOPORT_BASE_ADDRESS_STRING, 0, Value);

  if (Status == EFI_SUCCESS) {
    Temp = ASCIISTR_TO_INT(Value);
    //
    // Update attribute
    //
    if (Temp != 0) {
      Print(L"Override with UART IO PORT base %x registered in SCRT.conf file.\n", Temp);
      HandOffInfo->DebuggerInfo.MmioFlag = FALSE;
      HandOffInfo->DebuggerInfo.IoPort = Temp;
    } 
  }
  
}


