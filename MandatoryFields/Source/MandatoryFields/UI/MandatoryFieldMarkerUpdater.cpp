#include "stdafx.h"
#include "MandatoryFields/UI/MandatoryFieldMarkerUpdater.h"
#include "MandatoryFields/Data/MandatoryFieldsMap.h"

namespace Messerli::MandatoryFields::UI {

    MandatoryFieldMarkerUpdater::MandatoryFieldMarkerUpdater(Adapter::AbstractFieldAccessor& fieldAccessor, Data::Adapter::AbstractINIAccessor& iniAccessor)
        : m_fieldAccessor(fieldAccessor), m_iniAccessor(iniAccessor) 
    {}

    auto MandatoryFieldMarkerUpdater::Update() -> void
    {
        std::map<int, bool> mandatoryByStatic;
        for (let& field : Data::MandatoryFieldsMap) {
            if (field.StaticID == 0) {
                continue;
            }
            let isMandatory = m_iniAccessor.ReadBOOL(field.Group, field.key, false);
            mandatoryByStatic[field.StaticID] |= isMandatory;
        }
        for (let& [staticID, isMandatory] : mandatoryByStatic) {
            CString text = m_fieldAccessor.GetText(staticID);
            text.TrimRight();
            if (!text.IsEmpty() && text.Right(1) == _T("*")) {
                text = text.Left(text.GetLength() - 1);
                text.TrimRight();
            }
            if (isMandatory) {
                text += _T("*");
            }
            m_fieldAccessor.SetText(staticID, text);
        }
    }
}