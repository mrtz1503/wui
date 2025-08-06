#include "graphics/gdi/GDI_GraphicsDriver.h"

#include <WinUser.h>

namespace wui {

    void GDI_GraphicsDriver::rect(int x, int y, int w, int h)
    {
        ::FillRect();

    }



}

