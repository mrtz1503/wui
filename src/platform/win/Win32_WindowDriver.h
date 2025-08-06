#pragma once

#include "wui/WindowDriver.h"

#include <Windows.h>
#include <string>

#include "wui/gui/Widget.h"

namespace wui {

    class Win32WindowDriver : public WindowDriver {
    public:

        virtual void create() override;
        virtual bool created() override;
        virtual void destroy() override;


        virtual void resize(int x, int y, int width, int height) override;


        void setClassName(const std::wstring& name) { m_className = name; }
        
        virtual void flags(const std::set<Widget::Flag>& flags) override;



    private:

        static DWORD getStyleFromFlags(const std::set<Widget::Flag>& flags);
        static DWORD getExStyleFromFlags(const std::set<Widget::Flag>& flags);

        // subcall procedure for the window
        static LRESULT SubClassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);

        std::wstring m_className = L"WuiWindow";
        HWND m_hwnd;

        DWORD m_style = 0;
        DWORD m_exStyle = 0;
    };
}

