#pragma once
#include "MandatoryFields/UI/Adapter/AbstractFieldAccessor.h"
#include "MandatoryFields/UI/AbstractUpdater.h"
#include "MandatoryFields/Data/Adapter/AbstractINIAccessor.h"
#include "MandatoryFields/Data/Type/MandatoryFieldData.h"

namespace Messerli::MandatoryFields::BL {

class MANDATORYFIELDS_API MandatoryFieldService {
public:
    /// <summary>
    /// Konstruktor des Services.
    /// </summary>
    /// <param name="iniAccessor">Abstraktion für den Zugriff auf die gespeicherten Pflichtfeld-Konfigurationen.</param>
    /// <param name="accessor">Abstraktion für den Zugriff und die Manipulation von UI-Feldern.</param>
    /// <param name="updater">Updater für die visuelle Markierung der Pflichtfelder im UI.</param>
    MandatoryFieldService(Data::Adapter::AbstractINIAccessor& iniAccessor, UI::Adapter::AbstractFieldAccessor& accessor, UI::AbstractUpdater& updater);

    /// <summary>
    /// Validiert ein einzelnes Feld anhand seiner ID
    /// </summary>
    /// <param name="id">Die Control-ID des zu validierenden Feldes.</param>
    /// <param name="restoreFocus">Gibt an, ob der Fokus bei ungültigem Feld zurückgesetzt werden soll.</param>
    /// <returns>True, wenn das Feld gültig ist oder kein Pflichtfeld ist, ansonsten false.</returns>
    auto ValidateField(int id, bool restoreFocus) -> bool;

    /// <summary>
    /// Liefert die ID des ersten konfigurierten Pflichtfeldes.
    /// </summary>
    /// <returns>Die Control-ID des ersten Pflichtfeldes oder 0, falls keines existiert.</returns>
    auto GetFirstMandatoryField() -> int;

    /// <summary>
    /// Die Control-ID des ersten Pflichtfeldes oder 0, falls keines existiert.
    /// </summary>
    /// <param name="currentID">Die aktuelle Control-ID.</param>
    /// <returns>Die Control-ID des nächsten Pflichtfeldes oder 0, falls keines folgt.</returns>
    auto GetNextMandatoryField(int currentID) -> int;

    /// <summary>
    /// Aktualisiert die visuelle Darstellung der Pflichtfelder im UI.
    /// </summary>
    /// <returns>void</returns>
    auto UpdateMarkers() -> void;
private:
    auto FindField(int id) const -> const Data::Type::MandatoryFieldData*;

    Data::Adapter::AbstractINIAccessor& m_iniAccessor;
    UI::Adapter::AbstractFieldAccessor& m_fieldAccessor;
    UI::AbstractUpdater& m_updater;
};

}