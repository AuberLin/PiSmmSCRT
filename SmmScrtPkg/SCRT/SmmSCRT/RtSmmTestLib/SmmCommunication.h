/*++

Copyright (c) 2008, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  SmmCommunication.h

Abstract:

  Declarations for SMM Communication Protocol

--*/

#ifndef _RT_SMM_COMMUNICATION_H_
#define _RT_SMM_COMMUNICATION_H_

#define SIGNATURE_16(A, B)        ((A) | (B << 8))
#define SIGNATURE_32(A, B, C, D)  (SIGNATURE_16 (A, B) | (SIGNATURE_16 (C, D) << 16))
#define EFI_ACPI_4_0_UEFI_ACPI_DATA_TABLE_SIGNATURE  SIGNATURE_32('U', 'E', 'F', 'I')

//
// MAX buffer size to hold test assertions in one test smm handler.
//
#define MAX_COMMUNICATION_BUFFER_SIZE  2048

#define EFI_SMM_COMMUNICATION_PROTOCOL_GUID \
{ 0xc68ed8e2, 0x9dc6, 0x4cbd, { 0x9d, 0x94, 0xdb, 0x65, 0xac, 0xc5, 0xc3, 0x32 }}

EFI_FORWARD_DECLARATION (EFI_SMM_COMMUNICATION_PROTOCOL);

typedef struct {
  EFI_GUID        HeaderGuid;
  UINTN        MessageLength;
} EFI_SMM_COMMUNICATE_HEADER;


typedef
EFI_STATUS
(EFIAPI *EFI_SMM_COMMUNICATE) (
  IN CONST EFI_SMM_COMMUNICATION_PROTOCOL             * This,
  IN OUT VOID                               *CommBuffer,
  IN OUT UINTN  *CommSize
  );

typedef struct _EFI_SMM_COMMUNICATION_PROTOCOL {
  EFI_SMM_COMMUNICATE   Communicate;
} EFI_SMM_COMMUNICATION_PROTOCOL;

//
// Ensure proper structure formats
//
#pragma pack(1)
///
/// Root System Description Pointer Structure
///
typedef struct {
  UINT64  Signature;
  UINT8   Checksum;
  UINT8   OemId[6];
  UINT8   Revision;
  UINT32  RsdtAddress;
  UINT32  Length;
  UINT64  XsdtAddress;
  UINT8   ExtendedChecksum;
  UINT8   Reserved[3];
} EFI_ACPI_4_0_ROOT_SYSTEM_DESCRIPTION_POINTER;

typedef struct {
  UINT32  Signature;
  UINT32  Length;
  UINT8   Revision;
  UINT8   Checksum;
  UINT8   OemId[6];
  UINT64  OemTableId;
  UINT32  OemRevision;
  UINT32  CreatorId;
  UINT32  CreatorRevision;
} SMM_SCRT_EFI_ACPI_DESCRIPTION_HEADER;

typedef struct {
  SMM_SCRT_EFI_ACPI_DESCRIPTION_HEADER   Header;
  EFI_GUID                          Identifier;
  UINT16                        DataOffset;
} EFI_ACPI_DATA_TABLE;

typedef struct {
  EFI_ACPI_DATA_TABLE  UefiAcpiDataTable;
  UINT32               SwSmiNumber;
  UINT64               BufferPtrAddress;
} EFI_SMM_COMMUNICATION_ACPI_TABLE;

#pragma pack()

#endif
