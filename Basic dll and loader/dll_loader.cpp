#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("NOPE!! also pass a dll while calling this\n");
        return EXIT_FAILURE;
    }

    // Get the DLL file name from the command-line argument
    LPSTR dll_file = argv[1];

    // Load the DLL
    HINSTANCE hDLL = LoadLibraryA(dll_file);
    if (hDLL == NULL) {
        printf("Failed to load DLL: %d\n", GetLastError());
        return EXIT_FAILURE;
    }

    printf("DLL loaded successfully!\n");

    // ... (code to use the DLL functions)

    // Free the DLL
    FreeLibrary(hDLL);

    return EXIT_SUCCESS;
}

