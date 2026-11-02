#pragma once

namespace Messerli::MandatoryFields::Data {

class AbstractINIManager {
public:
    virtual ~AbstractINIManager() = default;

    /// <summary>
    /// Lädt die konfigurierten Pflichtfelder aus der INI - Tabelle
    /// </summary>
    /// <param name="listPerson">CheckListBox für personenbezogene Felder.</param>
    /// <param name="listAdress">CheckListBox für Adressfelder.</param>
    /// <returns>void</returns>
    virtual auto Load(CCheckListBox& listPerson, CCheckListBox& listAdress) -> void abstract;

    /// <summary>
    /// Speichert die aktuellen Zustände (angekreuzt/nicht angekreuzt)
    /// </summary>
    /// <param name="list">Speichert die aktuellen Zustände (angekreuzt/nicht angekreuzt)</param>
    /// <returns>void</returns>
    virtual auto Save(CCheckListBox& list) -> void abstract;
};

}