#include "stdafx.h"
#include "MandatoryFields/Data/INIManager.h"
#include "MandatoryFields/Data/MandatoryFieldsMap.h"

namespace Messerli::MandatoryFields::Data {

INIManager::INIManager(CMyINITable& ini)
    : m_ini(ini)
{}

auto INIManager::Load(CCheckListBox& listPerson, CCheckListBox& listAdress) -> void
{
    listPerson.ResetContent();
    listAdress.ResetContent();
    for (let& field : MandatoryFieldsMap) {
        CCheckListBox* list = nullptr;
        if (field.Group == _T("Person")) {
            list = &listPerson;
        }
        else if (field.Group == _T("Adress")) {
            list = &listAdress;
        }

        if (!list) {
            continue;
        }

        let idx = list->AddString(field.key);
        if (idx == LB_ERR) {
            continue;
        }

        list->SetItemData(idx, (DWORD_PTR)&field);
        let checked = m_ini.ReadBOOL(field.Group, field.key, false);
        list->SetCheck(idx, checked);
    }
}

auto INIManager::Save(CCheckListBox& list) -> void
{
    for (int i = 0; i < list.GetCount(); ++i) {
        let* field = reinterpret_cast<Data::Type::MandatoryFieldData*>(list.GetItemData(i));
        if (!field) {
            continue;
        }
        let checked = list.GetCheck(i);
        m_ini.WriteBOOL(field->Group, field->key, static_cast<bool>(checked));
    }
}

}