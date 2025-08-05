#include "platform/win/Win32_WindowDriver.h"

#include "platform/win/Win32_SystemDriver.h"

#include "wui/Window.h"
#include "wui/Application.h"

#include <commctrl.h>


#include <Windows.h>
namespace wui {

    void Win32WindowDriver::create()
    {
        
        if (Win32SystemDriver::hasClass(m_className))
        {
            WNDCLASSEXW wc = {};
            wc.cbSize = sizeof(WNDCLASSEXW);
            



            return;
        }



        ::SetWindowSubclass(m_hwnd, 
                            Win32WindowDriver::SubClassProc, 
                            reinterpret_cast<UINT_PTR>(this), 
                            reinterpret_cast<DWORD_PTR>(getWindow()));




    }


    void Win32WindowDriver::resize(int x, int y, int cx, int cy)
    {



    };

    LRESULT CALLBACK Win32WindowDriver::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {

        
        




    }


}