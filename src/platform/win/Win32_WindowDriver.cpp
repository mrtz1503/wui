#include "platform/win/Win32_WindowDriver.h"

#include "platform/win/Win32_SystemDriver.h"
#include "platform/win/Win32_Error.h"

#include "wui/Window.h"
#include "wui/Application.h"

#include <commctrl.h>


#include <Windows.h>

namespace wui {






    bool Win32WindowDriver::created()
    {
        return m_hwnd != nullptr;
    }




    void Win32WindowDriver::create()
    {

        Window* wnd = getWindow();
        const std::set<Widget::Flag>& flags = wnd->getFlags();

        if (flags.count(Widget::Flag::FramedWindow))
        {
            m_className = L"WuiFramedWindow";
        }

        if (!Win32SystemDriver::hasClass(m_className))
        {
            WNDCLASSEXW wc = {};
            wc.cbSize = sizeof(WNDCLASSEXW);
            wc.hInstance = Win32SystemDriver::getInst();
            wc.lpszClassName = m_className.c_str();
            wc.cbClsExtra = 0;
            wc.cbWndExtra = 0;
            wc.lpfnWndProc = ::DefWindowProcW;
            wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
            // wc.hCursor = ::LoadCursorW(nullptr, IDC_ARROW);
            //wc.hIcon = ::LoadIconW(nullptr, IDI_APPLICATION);
            //wc.hIconSm = ::LoadIconW(nullptr, IDI_APPLICATION);
            wc.style = CS_HREDRAW | CS_VREDRAW;
            wc.lpszMenuName = nullptr;

            ATOM classAtom = ::RegisterClassExW(&wc);
            if (!classAtom) { throw Win32Error("Win32WindowDriver::create -> ::RegisterClassExW() cannot register window class"); }
        }


        HWND hWnd = ::CreateWindowExW(m_exStyle,
                                      m_className.c_str(),
                                      L"",
                                      m_style,
                                      CW_USEDEFAULT,
                                      CW_USEDEFAULT,
                                      CW_USEDEFAULT,
                                      CW_USEDEFAULT,
                                      nullptr,
                                      nullptr,
                                      Win32SystemDriver::getInst(),
                                      nullptr);


        if (!hWnd) { throw Win32Error("Win32WindowDriver::create -> ::CreateWindowExW() cannot create window"); }

        m_hwnd = hWnd;

        ::SetWindowSubclass(m_hwnd,
                            Win32WindowDriver::SubClassProc,
                            reinterpret_cast<UINT_PTR>(this),
                            reinterpret_cast<DWORD_PTR>(getWindow()));

    }

    void Win32WindowDriver::destroy()
    {

    }





    void Win32WindowDriver::flags(const std::set<Widget::Flag>& flags)
    {
        if (flags.count(Widget::Flag::Visible))
        {
            ::ShowWindow(m_hwnd, SW_SHOW);
        }

        m_style = getStyleFromFlags(flags);
        m_exStyle = getExStyleFromFlags(flags);

        if (flags.count(Widget::Flag::FramedWindow))
        {
            m_className = L"WuiFramedWindow";
        }


    }


    DWORD Win32WindowDriver::getStyleFromFlags(const std::set<Widget::Flag>& flags)
    {
        DWORD style = 0;
        for each(Widget::Flag flag in flags)
        {
            switch (flag)
            {
                case wui::Widget::Visible:
                    break;
                case wui::Widget::Resizable:
                    break;
                case wui::Widget::Fullscreen:
                    break;
                case wui::Widget::Maximized:
                    break;
                case wui::Widget::Minimized:
                    break;
                case wui::Widget::FramedWindow:
                    style |= WS_OVERLAPPEDWINDOW;
                    style |= WS_VISIBLE;
                    break;
                default:
                    break;
            }
        }

        return style;
    }


    DWORD Win32WindowDriver::getExStyleFromFlags(const std::set<Widget::Flag>& flags)
    {
        return 0;
    }


    void Win32WindowDriver::resize(int x, int y, int width, int height)
    {
        Window* wnd = getWindow();
        ::SetWindowPos(m_hwnd, NULL, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
    };






    LRESULT Win32WindowDriver::SubClassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
    {
        Win32WindowDriver* drv = reinterpret_cast<Win32WindowDriver*>(uIdSubclass);
        Window* wnd = reinterpret_cast<Window*>(dwRefData);


        switch (uMsg)
        {



            case WM_NCDESTROY:
                ::RemoveWindowSubclass(hWnd, Win32WindowDriver::SubClassProc, uIdSubclass);
                break;
        }








        return ::DefSubclassProc(hWnd, uMsg, wParam, lParam);
    }


}