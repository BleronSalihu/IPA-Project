#include "stdafx.h"

#include <afxwin.h>
#include <afxdllx.h>

// Muss immer an letzter Stelle stehen
#include "Common/rmi_debug.h"

static AFX_EXTENSION_MODULE MandatoryFieldsDLL = {NULL, NULL};

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    UNREFERENCED_PARAMETER(lpReserved);

    if (dwReason == DLL_PROCESS_ATTACH) {
        OutputDebugString(_T("MandatoryFields.dll Begin DllMain DLL_PROCESS_ATTACH\r\n"));

        if (!AfxInitExtensionModule(MandatoryFieldsDLL, hInstance)) {
            return 0;
        }

        // Insert this DLL into the resource chain
        // NOTE: If this Extension DLL is being implicitly linked to by
        //  an MFC Regular DLL (such as an ActiveX Control)
        //  instead of an MFC application, then you will want to
        //  remove this line from DllMain and put it in a separate
        //  function exported from this Extension DLL.  The Regular DLL
        //  that uses this Extension DLL should then explicitly call that
        //  function to initialize this Extension DLL.  Otherwise,
        //  the CDynLinkLibrary object will not be attached to the
        //  Regular DLL's resource chain, and serious problems will
        //  result.

        new CDynLinkLibrary(MandatoryFieldsDLL);
        OutputDebugString(_T("MandatoryFields.dll End DllMain DLL_PROCESS_ATTACH\r\n"));
    } else if (dwReason == DLL_PROCESS_DETACH) {
        OutputDebugString(_T("MandatoryFields.dll Begin DllMain DLL_PROCESS_DETACH\r\n"));
        AfxTermExtensionModule(MandatoryFieldsDLL);
        OutputDebugString(_T("MandatoryFields.dll End DllMain DLL_PROCESS_DETACH\r\n"));
    }
    return 1;
}

///      Gibt den Instance-Handle auf diese DLL zurück.
HINSTANCE MandatoryFieldsGetInstanceHandle()
{
    _ASSERTE(MandatoryFieldsDLL.hModule != NULL);

    return MandatoryFieldsDLL.hModule;
}

///      Gibt den Resource-Handle auf diese DLL zurück.
HINSTANCE MandatoryFieldsGetResourceHandle()
{
    _ASSERTE(MandatoryFieldsDLL.hModule != NULL || MandatoryFieldsDLL.hResource != NULL);

    if (MandatoryFieldsDLL.hResource == NULL) {
        return MandatoryFieldsDLL.hModule;
    }

    return MandatoryFieldsDLL.hResource;
}

///      Fügt diese DLL dem Resource Chain hinzu
void MandatoryFieldsRegisterDLL()
{
    if (!MandatoryFieldsDLL.bInitialized) {
        _ASSERTE(false);
        return;
    }

    new CDynLinkLibrary(MandatoryFieldsDLL);
}

///      Für die Unit-Tests: Testet ob die Resourcen verfügbar sind.
bool MandatoryFieldsResourceTest()
{
    return true;
}
