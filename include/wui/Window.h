#pragma once

#include "wui/WindowDriver.h"
#include <memory>

namespace wui {
    class Window {
    public:

        Window();
        ~Window();

    private:

        // every window has a platform specific WindowDriver that contains the platform specific window data (e.g. HWND - Win32)
        std::shared_ptr<WindowDriver> m_driver; 
    };




}