#define _WIN32_WINNT 0x0500
#include <windows.h>

#include <SDL2/SDL.h>

 
 
 
int CALLBACK EnumWindowsProc(HWND hWnd, long lParam) {
    char buff[255];

    if (IsWindowVisible(hWnd)) {
        GetWindowText(hWnd, buff, 254);
        printf("%s\n", buff);
    }
    return 1;
}

int main() {
    EnumWindows(EnumWindowsProc, 0);
    return 0;
}
