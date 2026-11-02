#include "stdafx.h"
#include "MandatoryFields/UI/Adapter/FieldAccessor.h"

namespace Messerli::MandatoryFields::UI::Adapter {

FieldAccessor::FieldAccessor(CWnd* parent, std::set<int>& invalidFields)
    : m_parent(parent), m_invalidFields(invalidFields)
{}


auto FieldAccessor::GetText(int editID) const -> CString
{
    CString text;
    if (auto* edit = m_parent->GetDlgItem(editID)) {
        edit->GetWindowText(text);
    }
    return text;
}

auto FieldAccessor::SetText(int editID, const CString& text) -> void
{
    if (auto* edit = m_parent->GetDlgItem(editID)) {
        edit->SetWindowText(text);
    }
}

auto FieldAccessor::SetFocus(int editID) -> void
{
    if (auto* edit = m_parent->GetDlgItem(editID)) {
        edit->SetFocus();
    }
}

auto FieldAccessor::MarkInvalid(int editID) -> void
{
    m_invalidFields.insert(editID);
    if (auto* edit = m_parent->GetDlgItem(editID)) {
        edit->Invalidate();
    }
}

auto FieldAccessor::ClearInvalid(int editID) -> void
{
    m_invalidFields.erase(editID);
    if (auto* edit = m_parent->GetDlgItem(editID)) {
        edit->Invalidate();
    }
}

}