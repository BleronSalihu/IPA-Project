#pragma once
#include "MandatoryFields/Data/INIManager.h"

namespace Messerli::MandatoryFields::UI {

class MANDATORYFIELDS_API MandatoryFieldsConfiguratorDialog final : public tModalDialog {
    DECLARE_MESSAGE_MAP()
public:
    /// <summary>
    /// Konstruktor des Dialogs zur Konfiguration von Pflichtfeldern.
    /// </summary>
    /// <param name="wnd">Zeiger auf das Parent-Fenster.</param>
    explicit MandatoryFieldsConfiguratorDialog(CWnd* wnd);
protected:
    virtual auto OnInitDialog() -> BOOL override;
    virtual auto DoDataExchange(CDataExchange* pDX) -> void override;
    afx_msg auto OnButtonSave() -> void;

    enum Controls {
        IDC_LIST_PERSON = 1001,
        IDC_LIST_ADRESS = 1002
    };

private:
    CCheckListBox m_listPerson;
    CCheckListBox m_listAdress;
    std::unique_ptr<Data::AbstractINIManager> m_iniManager;
};

}