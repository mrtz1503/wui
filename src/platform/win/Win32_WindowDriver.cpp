#include "platform/win/Win32_WindowDriver.h"

#include "wui/Window.h"
#include "wui/Application.h"

#include <Windows.h>
namespace wui {

    void Win32WindowDriver::create()
    {



    }


    void Win32WindowDriver::resize(int x, int y, int cx, int cy)
    {



    };

    LRESULT CALLBACK Win32WindowDriver::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {

        wui::Application::findWindow(hWnd);








    }


}