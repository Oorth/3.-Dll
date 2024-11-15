#include <windows.h>
#pragma comment(lib, "user32.lib")

//dll proxy
#pragma comment(linker, "/export:DllCanUnloadNow=aepic.DllCanUnloadNow");
#pragma comment(linker, "/export:DllGetActivationFactory=aepic.DllGetActivationFactory");
#pragma comment(linker, "/export:GetAppInventoryCore=aepic.GetAppInventoryCore");
#pragma comment(linker, "/export:GetPrivacyLevel=aepic.GetPrivacyLevel");
#pragma comment(linker, "/export:PicAmiClose=aepic.PicAmiClose");
#pragma comment(linker, "/export:PicAmiInitialize=aepic.PicAmiInitialize");
#pragma comment(linker, "/export:PicFreeFileInfo=aepic.PicFreeFileInfo");
#pragma comment(linker, "/export:PicRetrieveFileInfo=aepic.PicRetrieveFileInfo");
#pragma comment(linker, "/export:PicRetrieveFileInfoAppx=aepic.PicRetrieveFileInfoAppx");
#pragma comment(linker, "/export:PicRetrieveFileLastRunTime=aepic.PicRetrieveFileLastRunTime");
#pragma comment(linker, "/export:PicUpdateFileLastRunTime=aepic.PicUpdateFileLastRunTime");
#pragma comment(linker, "/export:UpdateSoftwareInventoryTC2=aepic.UpdateSoftwareInventoryTC2");

BOOL WINAPI DllMain(HANDLE DLL, DWORD dwReason, LPVOID LpReserved)
{
    switch(dwReason)
    {
        case DLL_PROCESS_ATTACH:                
            MessageBoxW(NULL, L"hi", L"hello again", MB_OK | MB_ICONHAND);                
        break;
    }

    return TRUE;
}