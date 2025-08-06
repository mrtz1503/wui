#pragma once

#include "wui/WindowDriver.h"
#include <memory>

#include "wui/gui/Group.h"

namespace wui {
    class Window : public Group {
    public:

        Window();

        // show / create window
        virtual void show();
        // hide window
        virtual void hide();
        // close window
        virtual void close();


        // window created?
        virtual bool visible() const { return hasFlag(Flag::Visible); }


        virtual void setSize(int width, int height) override;

        virtual void addFlag(Flag flag) override {
            Group::addFlag(flag);
            m_drv->flags(getFlags());
        }

        virtual void removeFlag(Flag flag) override {
            Group::removeFlag(flag);
            m_drv->flags(getFlags());
        }

    protected:



    private:
        // every window has a platform specific WindowDriver that contains the platform specific window data (e.g. HWND - Win32)
        std::unique_ptr<WindowDriver> m_drv;

        

    };




}