#include "stdafx.h"
#include "ResStrings.h"

CString ResTHIS(UINT ResourceID, Sprache::eResStrUsage type)
{
    return Sprache::ResStrEx(MandatoryFieldsGetResourceHandle(), ResourceID, type);
}

CString ResTHIS(LPCTSTR lpszResString)
{
    return Sprache::ResStrEx(lpszResString);
}

CString ResTHIS(UINT ResourceID, Sprache::eSprache sprache)
{
    return Sprache::ResStrEx(MandatoryFieldsGetResourceHandle(), ResourceID, sprache);
}

CString ResMFS(UINT ResourceID, Sprache::eResStrUsage type)
{
    return Sprache::ResStrEx(MandatoryFieldsGetResourceHandle(), ResourceID, type);
}

CString ResMFS(LPCTSTR lpszResString)
{
    return Sprache::ResStrEx(lpszResString);
}

CString ResMFS(UINT ResourceID, Sprache::eSprache sprache)
{
    return Sprache::ResStrEx(MandatoryFieldsGetResourceHandle(), ResourceID, sprache);
}
