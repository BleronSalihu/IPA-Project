#pragma once

namespace Messerli::MandatoryFields::UI::Adapter {

class AbstractFieldAccessor {
public:
    virtual ~AbstractFieldAccessor() = default;

    /// <summary>
    /// Liest den aktuellen Textinhalt eines Feldes anhand seiner Control-ID.
    /// </summary>
    /// <param name="editID">Die Control-ID des Feldes.</param>
    /// <returns>void</returns>
    virtual auto GetText(int editID) const -> CString abstract;

    /// <summary>
    /// Setzt den Textinhalt eines Feldes anhand seiner Control-ID.
    /// </summary>
    /// <param name="editID">Die Control-ID des Feldes.</param>
    /// <param name="text">Der zu setzende Text.</param>
    /// <returns>void</returns>
    virtual auto SetText(int editID, const CString& text) -> void abstract;

    /// <summary>
    /// Setzt den Fokus auf das angegebene Feld.
    /// </summary>
    /// <param name="editID">Die Control-ID des Feldes.</param>
    /// <returns>void</returns>
    virtual auto SetFocus(int editID) -> void abstract;

    /// <summary>
    /// Markiert ein Feld visuell als ungültig
    /// </summary>
    /// <param name="editID">Die Control-ID des Feldes.</param>
    /// <returns>void</returns>
    virtual auto MarkInvalid(int editID) -> void abstract;

    /// <summary>
    /// Entfernt die visuelle Markierung eines Feldes als ungültig.
    /// </summary>
    /// <param name="editID">Die Control-ID des Feldes.</param>
    /// <returns>void</returns>
    virtual auto ClearInvalid(int editID) -> void abstract;
};

}