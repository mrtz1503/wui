#pragma once

#include "wui/WindowDriver.h"
#include <memory>

namespace wui {
    class Window {
    public:

        enum Styles {
            Framed = 1 << 0,
        };

        enum Flags {
            Shown = 1 << 0,
            Hidden = 1 << 1,
            Resizable = 1 << 2,
            Fullscreen = 1 << 3,
            Maximized = 1 << 4,
            Minimized = 1 << 5,

        };

        Window();

        virtual void show();

        virtual bool isShown() const { return m_flags & Flags::Shown; }


    private:
         // every window has a platform specific WindowDriver that contains the platform specific window data (e.g. HWND - Win32)
        std::unique_ptr<WindowDriver> m_driver;

        Flags m_flags;
    };




}