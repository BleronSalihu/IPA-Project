#pragma once
#include "AbstractINIAccessor.h"

namespace Messerli::MandatoryFields::Data::Adapter {

class MANDATORYFIELDS_API INIAccessor final : public AbstractINIAccessor {
public:
    INIAccessor(CMyINITable& ini);
    auto ReadBOOL(const CString& group, const CString& key, bool Deafult = false) -> bool override;
    auto WriteBOOL(const CString& group, const CString& key, bool value) -> bool override;
private:
    CMyINITable& m_ini;
};

}