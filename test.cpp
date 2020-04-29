#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include"src/Presenter.h"
#include"src/D2DPresenter.h"
#include<iostream>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

using namespace std;

int main()
{

    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"啦啦啦 Window Class";
    HINSTANCE hInstance = GetModuleHandle(0);
    WNDCLASS wc = { };
    wc.style          = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground  = CreateSolidBrush(RGB(220,220,220));

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
            0,                              // Optional window styles.
            CLASS_NAME,                     // Window class
            L"Learn to 啦啦啦 Windows",    // Window text
            WS_OVERLAPPEDWINDOW,            // Window style
            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
            NULL,       // Parent window
            NULL,       // Menu
            hInstance,  // Instance handle
            NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }


    ShowWindow(hwnd, SW_SHOW);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
switch (uMsg)
{
case WM_DESTROY:
PostQuitMessage(0);
return 0;

case WM_PAINT:
{
PAINTSTRUCT ps;
HDC hdc = BeginPaint(hwnd, &ps);

EndPaint(hwnd, &ps);
}
return 0;

}
return DefWindowProc(hwnd, uMsg, wParam, lParam);
}