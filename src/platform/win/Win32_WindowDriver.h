#pragma once

#include "wui/WindowDriver.h"

#include <Windows.h>

namespace wui {


    class Win32WindowDriver : public WindowDriver {
    public:

        virtual void create() override;
        virtual void resize(int x, int y, int cx, int cy) override;

        
    private:

        static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

        HWND m_hWnd;
    };




}

