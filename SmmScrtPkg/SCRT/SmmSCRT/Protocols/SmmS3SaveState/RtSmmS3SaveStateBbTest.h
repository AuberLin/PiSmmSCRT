/*++

Copyright (c) 2010, Intel Corporation
All rights reserved. This program and the accompanying materials
are licensed and made available under the terms and conditions of the Eclipse Public License
which accompanies this distribution.  The full text of the license may be found at
http://www.opensource.org/licenses/eclipse-1.0.php

THE PROGRAM IS DISTRIBUTED UNDER THE ECLIPSE PUBLIC LICENSE (EPL) ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  RtSmmS3SaveStateBbTest.h

Abstract:

  Runtime SmmS3SaveState Protocol Test.

--*/

#ifndef _RT_SMM_S3SAVESTATE_BB_TEST_H_
#define _RT_SMM_S3SAVESTATE_BB_TEST_H_

//
// Includes
//

#include "Efi.h"

//
// Definitions
//

#define S3SAVESTATE_PROTOCOL_CONFORMANCE_AUTO_GUID \
{ 0x41881fd0, 0xde50, 0x48bd, { 0x8a, 0x9a, 0x6f, 0x38, 0xfe, 0xad, 0x3, 0x38 } }

#define S3SAVESTATE_PROTOCOL_FUNCTION_AUTO_GUID \
{ 0xc59bbf83, 0x2ea1, 0x4bb0, { 0x9e, 0x28, 0x96, 0x77, 0xc5, 0xef, 0xa, 0xec } }




#define EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_001_GUID \
{ 0x61e59778, 0xd1f5, 0x4cc1, 0xa4, 0xd5, 0xbb, 0x90, 0x43, 0x31, 0x60, 0x16 }
extern EFI_GUID gS3SaveStateConformanceTestAssertionGuid001;

#define EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_002_GUID \
{ 0x49be6acf, 0xe0d7, 0x4f7f, 0x94, 0x1, 0x5d, 0x41, 0xd0, 0xc9, 0x72, 0x66 }
extern EFI_GUID gS3SaveStateConformanceTestAssertionGuid002;

#define EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_003_GUID \
{ 0x2de3932a, 0xa27a, 0x4a98, 0xbd, 0xfe, 0xa7, 0x85, 0xcd, 0x58, 0xa1, 0x94 } 
extern EFI_GUID gS3SaveStateConformanceTestAssertionGuid003;

#define EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_004_GUID \
{ 0xa9ad1d6b, 0xfcd9, 0x4401, 0xb9, 0xc, 0xe1, 0xef, 0xbd, 0xbd, 0x91, 0xea } 
extern EFI_GUID gS3SaveStateConformanceTestAssertionGuid004;

#define EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_005_GUID \
{ 0x1af9442f, 0x6b98, 0x411e, 0xb7, 0x5c, 0xc1, 0xf0, 0x7, 0x61, 0xda, 0x9b } 
extern EFI_GUID gS3SaveStateConformanceTestAssertionGuid005;

#define EFI_TEST_S3SAVESTATE_CONFORMANCETEST_ASSERTION_006_GUID \
{ 0x53271944, 0x2292, 0x4a3c, 0x86, 0xd, 0x63, 0xd0, 0x4e, 0xd8, 0x39, 0xed} 
extern EFI_GUID gS3SaveStateConformanceTestAssertionGuid006;


#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_001_GUID \
{ 0xf707068d, 0x671, 0x446d,  0xa2, 0xea, 0x31, 0x54, 0x8e, 0xcf, 0x5b, 0x4a }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid001;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_002_GUID \
{ 0x883a4238, 0xb139, 0x4e2a, 0xb6, 0x41, 0x79, 0x43, 0x9, 0x75, 0xdc, 0x7d }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid002;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_003_GUID \
{ 0x37890e1d, 0x81ea, 0x4c7a, 0x90, 0xf8, 0x6c, 0xc6, 0xb4, 0x69, 0xe3, 0x95 }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid003;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_004_GUID \
{ 0x40796e38, 0x5564, 0x4ddc, 0xa6, 0xcb, 0x92, 0x1d, 0x78, 0x70, 0x63, 0xc1 }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid004;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_005_GUID \
{ 0xe9ee0786, 0x848b, 0x4057, 0x84, 0xa0, 0xa6, 0xac, 0x25, 0x7b, 0xaa, 0x9d }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid005;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_006_GUID \
{ 0xe36420d9, 0xd5e2, 0x4973, 0x96, 0x5c, 0x6d, 0x68, 0x27, 0xe7, 0xc9, 0xa1 }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid006;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_007_GUID \
{ 0xe5e952f6, 0x54bd, 0x4680, 0xba, 0xef, 0x1d, 0xcc, 0x98, 0xc7, 0xa9, 0xb2 }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid007;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_008_GUID \
{ 0xc60b813e, 0xc3cc, 0x49ed, 0x9b, 0xe8, 0x9b, 0xd5, 0xfb, 0xe1, 0x6b, 0xdd }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid008;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_009_GUID \
{ 0x9814f51d, 0xcf65, 0x458c, 0x96, 0xc2, 0x70, 0x94, 0x6c, 0xab, 0x23, 0xd2 }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid009;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_010_GUID \
{ 0x953c98eb, 0x687d, 0x4918, 0x8d, 0x45, 0x33, 0xa, 0xb9, 0x9c, 0xe8, 0x9b  }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid010;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_011_GUID \
{ 0xcca4d3b8, 0x242e, 0x4d08, 0xaf, 0x1d, 0x62, 0x2f, 0xa7, 0x8a, 0x8d, 0xbe  }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid011;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_012_GUID \
{ 0xef467e03, 0x1982, 0x4311, 0xae, 0xf3, 0x1, 0x98, 0x53, 0x47, 0x1e, 0x72  }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid012;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_013_GUID \
{ 0x2cbe28fa, 0xb889, 0x46d6, 0x97, 0x9c, 0x5e, 0xfb, 0x21, 0x2f, 0x19, 0x83  }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid013;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_014_GUID \
{ 0xfb8c78eb, 0x8b8e, 0x464e, 0xa3, 0x6, 0x83, 0x43, 0x39, 0xed, 0x47, 0xfb }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid014;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_015_GUID \
{ 0xe56030c4, 0xb777, 0x4e79, 0x9b, 0x36, 0x2e, 0x33, 0x4e, 0x8a, 0xcb, 0x85  }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid015;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_016_GUID \
{ 0x26efde44, 0x835, 0x431d, 0x8c, 0x87, 0x1f, 0x68, 0x27, 0x56, 0x69, 0x7  }
extern EFI_GUID gS3SaveStateFunctionTestAssertionGuid016;

#define EFI_TEST_S3SAVESTATE_FUNCTIONTEST_ASSERTION_017_GUID \
{ 0x396b179a, 0x1d3f, 0x4531, 0x99, 0x6d, 0x1b, 0xde, 0xe2, 0x7a, 0x52, 0xf5  }


//
// Prototype of conformance tests
//

EFI_STATUS
RtSmmS3SaveStateConfBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );


EFI_STATUS
RtSmmS3SaveStateFuncBbTest (
  IN  EFI_RUNTIME_SERVICES  *vRT
  );


#endif
