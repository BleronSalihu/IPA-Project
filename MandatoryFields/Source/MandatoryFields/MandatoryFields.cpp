#include "stdafx.h"
#include "MandatoryFields/MandatoryFields.h"

namespace Messerli::MandatoryFields
{
    auto UsesResources() -> bool
    {
        bool resourceFound = false;
        #ifdef IDS_MFS_TESTRESOURCE
        resourceFound = true;
        #endif
        let resource = _T("MandatoryFields_Test resource: MFS");
        bool firstResourceRead = true;
        firstResourceRead &= ResMFS(IDS_MFS_TESTRESOURCE, Core::Language::eSprache::German) == resource;
        firstResourceRead &= ResMFS(IDS_MFS_TESTRESOURCE, Core::Language::eSprache::Italian) == resource;
        firstResourceRead &= ResMFS(IDS_MFS_TESTRESOURCE, Core::Language::eSprache::French) == resource;
        return resourceFound && firstResourceRead;
    }

    auto UsesRmiMyDb() -> bool
    {
        return RMIMyDB::IsAvailable();
    }
}
