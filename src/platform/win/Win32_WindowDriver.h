#pragma once

#include "wui/WindowDriver.h"

namespace wui {

    class Win32WindowDriver : public WindowDriver {
    public:

        virtual void create() override;
        virtual void resize(int x, int y, int cx, int cy) override;

        

    private:
        HWND hWnd;
    };




}