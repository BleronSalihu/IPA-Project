#include "stdafx.h"
#include "MandatoryFields/UI/MandatoryFieldsConfiguratorDialog.h"
#include "MandatoryFields/Data/MandatoryFieldsMap.h"
#include "MandatoryFields/Data/Adapter/INIAccessor.h"

namespace Messerli::MandatoryFields::UI {

BEGIN_MESSAGE_MAP(MandatoryFieldsConfiguratorDialog, tModalDialog)
    ON_BN_CLICKED(IDOK, &MandatoryFieldsConfiguratorDialog::OnButtonSave)
END_MESSAGE_MAP()

MandatoryFieldsConfiguratorDialog::MandatoryFieldsConfiguratorDialog(CWnd* wnd)
    : tModalDialog(IDD_MANDATORYFIELDSCONFIGURATOR, wnd)
{}

auto MandatoryFieldsConfiguratorDialog::OnInitDialog() -> BOOL
{
    tModalDialog::OnInitDialog();
    auto& ini = *Authentication::GetLoginUser()->GetGlobalIniTable();
    m_iniManager = std::make_unique<Data::INIManager>(ini);
    m_iniManager->Load(m_listPerson, m_listAdress);
    return true;
}

auto MandatoryFieldsConfiguratorDialog::DoDataExchange(CDataExchange* pDX) -> void
{
    tModalDialog::DoDataExchange(pDX);
    DDX_Control(pDX, Controls::IDC_LIST_ADRESS, m_listAdress);
    DDX_Control(pDX, Controls::IDC_LIST_PERSON, m_listPerson);
}

auto MandatoryFieldsConfiguratorDialog::OnButtonSave() -> void
{
    m_iniManager->Save(m_listAdress);
    m_iniManager->Save(m_listPerson);
    EndDialog(IDOK);
}

}