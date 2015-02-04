#/*++
#
# Copyright (c) 2010, Intel Corporation
# All rights reserved. This program and the accompanying materials
# are licensed and made available under the terms and conditions of the Eclipse Public License
# which accompanies this distribution.  The full text of the license may be found at
# http://www.opensource.org/licenses/eclipse-1.0.php
#
# THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
# Module Name:
#
#   SmmScrtPkg.dsc
#
# Abstract:
#
#   This is a build description file used to build the test modules
#
#
# Notes:
#
#   The info in this file is broken down into sections. The start of a section
#   is designated by a "[" in the first column. So the [=====] separater ends
#   a section.
#
#--*/

[Defines]
  PLATFORM_NAME                  = SmmScrtPkg
  PLATFORM_GUID                  = 5FD3F51F-EC29-461d-BBB9-4765405E5771
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/SmmScrtPkg
  SUPPORTED_ARCHITECTURES        = IA32|X64
  BUILD_TARGETS                  = DEBUG
  SKUID_IDENTIFIER               = DEFAULT
  
  EDK_GLOBAL SHELL_SOURCE = EdkCompatibilityPkg\Other\Maintained\Application\Shell

  
[SkuIds]
  0|DEFAULT              # The entry: 0|DEFAULT is reserved and always required.
  
[BuildOptions]
  *_*_IA32_CC_FLAGS    = /D EFI_DEBUG /D EFI_SPECIFICATION_VERSION=0x0002001E  /D PI_SPECIFICATION_VERSION=0x00010002  /D TIANO_RELEASE_VERSION=0x00080006
  *_*_IA32_ASM_FLAGS   = /DEFI32
  *_*_IA32_APP_FLAGS   = /D EFI_DEBUG /D EFI_SPECIFICATION_VERSION=0x0002001E  /D PI_SPECIFICATION_VERSION=0x00010002  /D TIANO_RELEASE_VERSION=0x00080006 
  *_*_IA32_PP_FLAGS    = /D EFI_DEBUG /D EFI_SPECIFICATION_VERSION=0x0002001E  /D PI_SPECIFICATION_VERSION=0x00010002  /D TIANO_RELEASE_VERSION=0x00080006 

  *_*_X64_CC_FLAGS    = /D EFI_DEBUG /D EFI_SPECIFICATION_VERSION=0x0002001E  /D PI_SPECIFICATION_VERSION=0x00010002  /D TIANO_RELEASE_VERSION=0x00080006
  *_*_X64_ASM_FLAGS   = /DEFIX64  
  *_*_X64_APP_FLAGS   = /D EFI_DEBUG /D EFI_SPECIFICATION_VERSION=0x0002001E  /D PI_SPECIFICATION_VERSION=0x00010002  /D TIANO_RELEASE_VERSION=0x00080006
  *_*_X64_PP_FLAGS    = /D EFI_DEBUG /D EFI_SPECIFICATION_VERSION=0x0002001E  /D PI_SPECIFICATION_VERSION=0x00010002  /D TIANO_RELEASE_VERSION=0x00080006
  
  
[Libraries]

EdkCompatibilityPkg\Foundation\Library\CompilerStub\CompilerStubLib.inf
EdkCompatibilityPkg\Foundation\Guid\EdkGuidLib.inf
EdkCompatibilityPkg\Foundation\Framework\Guid\EdkFrameworkGuidLib.inf
EdkCompatibilityPkg\Foundation\Efi\Guid\EfiGuidLib.inf
EdkCompatibilityPkg\Foundation\Library\EfiCommonLib\EfiCommonLib.inf
EdkCompatibilityPkg\Foundation\Cpu\Pentium\CpuIA32Lib\CpuIA32Lib.inf
EdkCompatibilityPkg\Foundation\Framework\Ppi\EdkFrameworkPpiLib.inf
EdkCompatibilityPkg\Foundation\Protocol\EdkProtocolLib.inf
EdkCompatibilityPkg\Foundation\Framework\Protocol\EdkFrameworkProtocolLib.inf
EdkCompatibilityPkg\Foundation\Efi\Protocol\EfiProtocolLib.inf
EdkCompatibilityPkg\Foundation\Core\Dxe\ArchProtocol\ArchProtocolLib.inf
EdkCompatibilityPkg\Foundation\Library\Dxe\EfiDriverLib\EfiDriverLib.inf
EdkCompatibilityPkg\Foundation\Library\Dxe\Print\PrintLib.inf
EdkCompatibilityPkg\Foundation\Library\Dxe\Hob\HobLib.inf

EdkCompatibilityPkg\Other\Maintained\Application\Shell\Library\EfiShellLib.inf

# Library used by SMM SCRT
SmmScrtPkg\SCRT\SmmSCRT\RtSmmTestLib\RtSmmTestLib.inf



[Components.common]

#
#SMM SCRT Driver & App
#
SmmScrtPkg\SCRT\SCRTDriver\SmmSCRTDriver.inf
SmmScrtPkg\SCRT\SCRTApp\SCRTApp.inf

