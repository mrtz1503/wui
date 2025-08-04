#pragma once

#include "wui/WindowDriver.h"

#include <Windows.h>

namespace wui {
    class Win32_WindowDriver : public WindowDriver {
    public:

        virtual void create() override; 


    private:




        HWND m_hWnd;
    };
} // namespace wui  