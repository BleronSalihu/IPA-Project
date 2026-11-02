#include "stdafx.h"
#include "MandatoryFields/Data/Adapter/INIAccessor.h"

namespace Messerli::MandatoryFields::Data::Adapter {

INIAccessor::INIAccessor(CMyINITable& ini)
    : m_ini(ini)
{}

auto INIAccessor::ReadBOOL(const CString& group, const CString& key, bool Default ) -> bool
{
    return m_ini.ReadBOOL(group, key, Default);
}

auto INIAccessor::WriteBOOL(const CString& group, const CString& key, bool value) -> bool
{
    return m_ini.WriteBOOL(group, key, value);
}

}