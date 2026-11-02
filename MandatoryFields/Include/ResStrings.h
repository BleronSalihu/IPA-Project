//================================================================================================
//   Copyright (c)   Messerli Informatik AG, CH-8957 Spreitenbach
//================================================================================================
#pragma once

HINSTANCE MandatoryFieldsGetResourceHandle(); // from dllmain.cpp

CString ResTHIS(UINT ResourceID, Sprache::eResStrUsage type);
CString ResTHIS(LPCTSTR lpszResString);
CString ResTHIS(UINT ResourceID, Sprache::eSprache sprache);

MANDATORYFIELDS_API CString ResMFS(UINT ResourceID, Sprache::eResStrUsage type = Sprache::eResStrUsage::Program);
MANDATORYFIELDS_API CString ResMFS(LPCTSTR lpszResString);
MANDATORYFIELDS_API CString ResMFS(UINT ResourceID, Sprache::eSprache sprache);
