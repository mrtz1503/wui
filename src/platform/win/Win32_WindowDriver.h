#pragma once

#include "wui/WindowDriver.h"

#include <Windows.h>
#include <unordered_map>
#include <string>

namespace wui {

    class Win32WindowDriver : public WindowDriver {
    public:

        virtual void create() override;
        virtual void resize(int x, int y, int cx, int cy) override;

        std::wstring getDefClassName() const {
            return L"WuiWindow";
        }

    private:

        // subcall procedure for the window
        static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        static LRESULT SubClassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);

        HWND m_hwnd;
    };
}

