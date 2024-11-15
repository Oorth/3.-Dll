#include <windows.h>
#pragma comment(lib, "user32.lib")

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