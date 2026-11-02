#include "stdafx.h"
#include "MandatoryFields/BL/MandatoryService.h"
#include "MandatoryFields/Data/MandatoryFieldsMap.h"

namespace Messerli::MandatoryFields::BL {

MandatoryFieldService::MandatoryFieldService(Data::Adapter::AbstractINIAccessor& iniAccessor, UI::Adapter::AbstractFieldAccessor& fieldAccessor, UI::AbstractUpdater& updater)
    : m_iniAccessor(iniAccessor), m_fieldAccessor(fieldAccessor), m_updater(updater)
{}

auto MandatoryFieldService::ValidateField(int id, bool restoreFocus) -> bool
{
    let* field = FindField(id);
    if (!field) {
        return true;
    }
    if (!m_iniAccessor.ReadBOOL(field->Group, field->key, false)) {
        m_fieldAccessor.ClearInvalid(id);
        return true;
    }
    if (m_fieldAccessor.GetText(id).IsEmpty()) {
        m_fieldAccessor.MarkInvalid(id);
        if (restoreFocus) {
            m_fieldAccessor.SetFocus(id);
        }
        return false;
    }
    m_fieldAccessor.ClearInvalid(id);
    return true;
}

auto MandatoryFieldService::GetFirstMandatoryField() -> int
{
    for (let& field : Data::MandatoryFieldsMap) {
        if (m_iniAccessor.ReadBOOL(field.Group, field.key, false))
            return field.EditID;
    }
    return 0;
}

auto MandatoryFieldService::GetNextMandatoryField(int currentID) -> int
{
    bool found = false;
    for (let& field : Data::MandatoryFieldsMap) {
        if (!m_iniAccessor.ReadBOOL(field.Group, field.key, false)) {
            continue;
        }
        if (found) {
            return field.EditID;
        }
        if (field.EditID == currentID) {
            found = true;
        }
    }
    return 0;
}

auto MandatoryFieldService::UpdateMarkers() -> void
{
    m_updater.Update();
}

auto MandatoryFieldService::FindField(int id) const -> const Data::Type::MandatoryFieldData*
{
    for (let& field : Data::MandatoryFieldsMap) {
        if (field.EditID == id)
            return &field;
    }
    return nullptr;
}

}