#pragma once
#include "AbstractINIManager.h"

namespace Messerli::MandatoryFields::Data {

class MANDATORYFIELDS_API INIManager final : public AbstractINIManager {
public:
    explicit INIManager(CMyINITable& ini);
    auto Load(CCheckListBox& listPerson, CCheckListBox& listAdress) -> void override;
    auto Save(CCheckListBox& list) -> void override;
private:
    CMyINITable& m_ini;
};

}