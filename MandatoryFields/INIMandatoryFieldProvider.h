#pragma once
#include "AbstractMandatoryFieldProvider.h"

namespace Messerli::MandatoryFields::BL::Provider {

class INIMandatoryFieldProvider : public AbstractMandatoryFieldProvider {
public:
    explicit INIMandatoryFieldProvider(CMyINITable& ini);
    auto IsMandatory(int editID) const -> bool override;
    auto GetMandatoryFields() const -> const std::vector<Data::Type::MandatoryFieldData> & override;
private:
    CMyINITable& m_ini;
};

}