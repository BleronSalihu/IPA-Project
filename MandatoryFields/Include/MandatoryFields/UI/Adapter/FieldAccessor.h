#pragma once
#include "AbstractFieldAccessor.h"

namespace Messerli::MandatoryFields::UI::Adapter {

class MANDATORYFIELDS_API FieldAccessor final : public AbstractFieldAccessor {
public:
    explicit FieldAccessor(CWnd* parent, std::set<int>& invalidFields);
    auto GetText(int editID) const -> CString override;
    auto SetText(int editID, const CString& text) -> void override;
    auto SetFocus(int editID) -> void override;
    auto MarkInvalid(int editID) -> void override;
    auto ClearInvalid(int editID) -> void override;
private:
    CWnd* m_parent;
    std::set<int>& m_invalidFields;
};

}