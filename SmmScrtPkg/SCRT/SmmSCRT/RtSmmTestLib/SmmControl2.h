/*++

Copyright (c) 2011, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  SmmControl2.h

Abstract:

  Declarations for SMM Control2 Protocol

--*/

#ifndef _RT_SMM_CONTROL2_H_
#define _RT_SMM_CONTROL2_H_

#define EFI_SMM_CONTROL2_PROTOCOL_GUID \
  { \
    0x843dc720, 0xab1e, 0x42cb, {0x93, 0x57, 0x8a, 0x0, 0x78, 0xf3, 0x56, 0x1b}  \
  }

typedef struct _EFI_SMM_CONTROL2_PROTOCOL  EFI_SMM_CONTROL2_PROTOCOL;
typedef UINTN  EFI_SMM_PERIOD;

/**
  Invokes SMI activation from either the preboot or runtime environment.

  This function generates an SMI.

  @param[in]     This                The EFI_SMM_CONTROL2_PROTOCOL instance.
  @param[in,out] CommandPort         The value written to the command port.
  @param[in,out] DataPort            The value written to the data port.
  @param[in]     Periodic            Optional mechanism to engender a periodic stream.
  @param[in]     ActivationInterval  Optional parameter to repeat at this period one
                                     time or, if the Periodic Boolean is set, periodically.

  @retval EFI_SUCCESS            The SMI/PMI has been engendered.
  @retval EFI_DEVICE_ERROR       The timing is unsupported.
  @retval EFI_INVALID_PARAMETER  The activation period is unsupported.
  @retval EFI_NOT_STARTED        The SMM base service has not been initialized.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_SMM_ACTIVATE2)(
  IN CONST EFI_SMM_CONTROL2_PROTOCOL  *This,
  IN OUT UINT8                        *CommandPort       OPTIONAL,
  IN OUT UINT8                        *DataPort          OPTIONAL,
  IN BOOLEAN                          Periodic           OPTIONAL,
  IN UINTN                            ActivationInterval OPTIONAL
  );

/**
  Clears any system state that was created in response to the Trigger() call.

  This function acknowledges and causes the deassertion of the SMI activation source.

  @param[in] This                The EFI_SMM_CONTROL2_PROTOCOL instance.
  @param[in] Periodic            Optional parameter to repeat at this period one time

  @retval EFI_SUCCESS            The SMI/PMI has been engendered.
  @retval EFI_DEVICE_ERROR       The source could not be cleared.
  @retval EFI_INVALID_PARAMETER  The service did not support the Periodic input argument.
**/
typedef
EFI_STATUS
(EFIAPI *EFI_SMM_DEACTIVATE2)(
  IN CONST EFI_SMM_CONTROL2_PROTOCOL  *This,
  IN BOOLEAN                          Periodic OPTIONAL
  );

///
/// The EFI_SMM_CONTROL2_PROTOCOL is produced by a runtime driver. It provides  an 
/// abstraction of the platform hardware that generates an SMI.  There are often I/O ports that, when 
/// accessed, will generate the SMI.  Also, the hardware optionally supports the periodic generation of 
/// these signals.
///
struct _EFI_SMM_CONTROL2_PROTOCOL {
  EFI_SMM_ACTIVATE2    Trigger;
  EFI_SMM_DEACTIVATE2  Clear;
  ///
  /// Minimum interval at which the platform can set the period.  A maximum is not 
  /// specified in that the SMM infrastructure code can emulate a maximum interval that is 
  /// greater than the hardware capabilities by using software emulation in the SMM 
  /// infrastructure code.
  ///
  EFI_SMM_PERIOD      MinimumTriggerPeriod;
};

#endif
