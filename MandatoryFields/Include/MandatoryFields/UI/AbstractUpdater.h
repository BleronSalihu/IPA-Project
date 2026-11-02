#pragma once

namespace Messerli::MandatoryFields::UI {

class AbstractUpdater {
public:
    virtual ~AbstractUpdater() = default;

    /// <summary>
    /// Aktualisiert die visuelle Darstellung der Pflichtfelder im UI.
    /// </summary>
    /// <returns>void</returns>
    virtual auto Update() -> void abstract;
};

}