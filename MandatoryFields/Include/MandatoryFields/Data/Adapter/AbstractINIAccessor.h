#pragma once

namespace Messerli::MandatoryFields::Data::Adapter {

class AbstractINIAccessor {
public:
    virtual ~AbstractINIAccessor() = default;

    /// <summary>
    /// Liest einen booleschen Wert aus der Konfigurationsquelle basierend auf Gruppe und Schlüssel.
    /// </summary>
    /// <param name="group">Die logische Gruppe des Eintrags.</param>
    /// <param name="key">Der eindeutige Schlüssel innerhalb der Gruppe.</param>
    /// <param name="Default">Fallback-Wert, falls kein Eintrag existiert.</param>
    /// <returns>True oder false je nach gespeichertem oder Default-Wert.</returns>
    virtual auto ReadBOOL(const CString& group, const CString& key, bool Default) -> bool abstract;

    /// <summary>
    /// Schreibt einen booleschen Wert in die Konfigurationsquelle basierend auf Gruppe und Schlüssel.
    /// </summary>
    /// <param name="group">Die logische Gruppe des Eintrags.</param>
    /// <param name="key">Der eindeutige Schlüssel innerhalb der Gruppe.</param>
    /// <param name="value">Der zu speichernde boolesche Wert.</param>
    /// <returns>True, wenn der Schreibvorgang erfolgreich war, ansonsten false.</returns>
    virtual auto WriteBOOL(const CString& group, const CString& key, bool value) -> bool abstract;
};

}