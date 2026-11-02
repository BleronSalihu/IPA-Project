#pragma once
#include "MandatoryFields/Data/Type/MandatoryFieldData.h"
#include <vector>

namespace Messerli::MandatoryFields::Data {

    const std::vector<Type::MandatoryFieldData> MandatoryFieldsMap{
        // --- Person ---
        { 205, 1730, _T("Person"), _T("Vorname") },
        //{ 204, 0,    _T("Person"), _T("Nachname") },
        { 240, 1750, _T("Person"), _T("Geburtsdatum") },
        { 207, 1732, _T("Person"), _T("Person") },
        { 222, 0,    _T("Person"), _T("Titel") },

        // --- Adresse ---
        { 209, 1733, _T("Adress"), _T("Strasse") },
        { 210, 1735, _T("Adress"), _T("PLZ") },
        { 211, 1735, _T("Adress"), _T("Ort") },
        { 208, 1734, _T("Adress"), _T("Postfach") },
        { 212, 1736, _T("Adress"), _T("Land") },

        // --- Kommunikation ---
        { 224, 1738, _T("Adress"), _T("Email") },
        { 234, 1737, _T("Adress"), _T("Homepage") },
        { 213, 1740, _T("Adress"), _T("TelefonPrivat") },
        { 214, 1739, _T("Adress"), _T("TelefonGeschaeft") },
        { 215, 1741, _T("Adress"), _T("Fax") },
        { 216, 1742, _T("Adress"), _T("Natel") }
    };

}