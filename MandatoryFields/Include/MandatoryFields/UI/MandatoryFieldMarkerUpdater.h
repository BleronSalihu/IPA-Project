#pragma once
#include "AbstractUpdater.h"
#include "MandatoryFields/UI/Adapter/AbstractFieldAccessor.h"
#include "MandatoryFields/Data/Adapter/AbstractINIAccessor.h"

namespace Messerli::MandatoryFields::UI {

class MANDATORYFIELDS_API MandatoryFieldMarkerUpdater final : public AbstractUpdater {
public:
    MandatoryFieldMarkerUpdater(Adapter::AbstractFieldAccessor& accessor, Data::Adapter::AbstractINIAccessor& iniAccessor);
    auto Update() -> void override;
private:
    Data::Adapter::AbstractINIAccessor& m_iniAccessor;
    Adapter::AbstractFieldAccessor& m_fieldAccessor;
};

}