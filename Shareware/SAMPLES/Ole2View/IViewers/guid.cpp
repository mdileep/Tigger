// guid.cpp
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) 1992-1993 Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and Microsoft
// QuickHelp and/or WinHelp documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
#include "stdafx.h"
#include <initguid.h>
#include "iviewers.h"

#if 1
const IID IID_IEnumGUID = {0x0002E000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const IID IID_IEnumCATEGORYINFO = {0x0002E011,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const IID IID_ICatRegister = {0x0002E012,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const IID IID_ICatInformation = {0x0002E013,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const CLSID CLSID_StdComponentCategoriesMgr = {0x0002E005,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

const CATID CATID_Insertable            = {0x40FC6ED3,0x2438,0x11cf,{0xA3,0xDB,0x08,0x00,0x36,0xF1,0x25,0x02}};
const CATID CATID_Control               = {0x40FC6ED4,0x2438,0x11cf,{0xA3,0xDB,0x08,0x00,0x36,0xF1,0x25,0x02}};
const CATID CATID_Programmable          = {0x40FC6ED5,0x2438,0x11cf,{0xA3,0xDB,0x08,0x00,0x36,0xF1,0x25,0x02}};
const CATID CATID_IsShortcut            = {0x40FC6ED6,0x2438,0x11cf,{0xA3,0xDB,0x08,0x00,0x36,0xF1,0x25,0x02}};
const CATID CATID_NeverShowExt          = {0x40FC6ED7,0x2438,0x11cf,{0xA3,0xDB,0x08,0x00,0x36,0xF1,0x25,0x02}};
const CATID CATID_DocObject             = {0x40FC6ED8,0x2438,0x11cf,{0xA3,0xDB,0x08,0x00,0x36,0xF1,0x25,0x02}};
const CATID CATID_Printable             = {0x40FC6ED9,0x2438,0x11cf,{0xA3,0xDB,0x08,0x00,0x36,0xF1,0x25,0x02}};
const CATID CATID_RequiresDataPathHost  = {0x0de86a50,0x2baa,0x11cf,{0xa2,0x29,0x00,0xaa,0x00,0x3d,0x73,0x52}};
const CATID CATID_PersistsToMoniker     = {0x0de86a51,0x2baa,0x11cf,{0xa2,0x29,0x00,0xaa,0x00,0x3d,0x73,0x52}};
const CATID CATID_PersistsToStorage     = {0x0de86a52,0x2baa,0x11cf,{0xa2,0x29,0x00,0xaa,0x00,0x3d,0x73,0x52}};
const CATID CATID_PersistsToStreamInit  = {0x0de86a53,0x2baa,0x11cf,{0xa2,0x29,0x00,0xaa,0x00,0x3d,0x73,0x52}};
const CATID CATID_PersistsToStream      = {0x0de86a54,0x2baa,0x11cf,{0xa2,0x29,0x00,0xaa,0x00,0x3d,0x73,0x52}};
const CATID CATID_PersistsToMemory      = {0x0de86a55,0x2baa,0x11cf,{0xa2,0x29,0x00,0xaa,0x00,0x3d,0x73,0x52}};
const CATID CATID_PersistsToFile        = {0x0de86a56,0x2baa,0x11cf,{0xa2,0x29,0x00,0xaa,0x00,0x3d,0x73,0x52}};
const CATID CATID_PersistsToPropertyBag = {0x0de86a57,0x2baa,0x11cf,{0xa2,0x29,0x00,0xaa,0x00,0x3d,0x73,0x52}};
#endif
