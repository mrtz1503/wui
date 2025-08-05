#pragma once

#include "wui/WindowDriver.h"
#include <memory>

#include "wui/gui/Group.h"

#include <set>

namespace wui {
    class Window : public Group {
    public:

        


    public:

        Window();

        virtual void show();

        virtual bool isVisible() const { return hasFlag(Flag::Visible); }



    protected:



    private:
        // every window has a platform specific WindowDriver that contains the platform specific window data (e.g. HWND - Win32)
        std::unique_ptr<WindowDriver> m_drv;

        
    };




}