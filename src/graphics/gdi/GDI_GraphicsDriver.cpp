#include "graphics/gdi/GDI_GraphicsDriver.h"

#include <WinUser.h>
#include <windows.h>

namespace wui {

    void GraphicsDriver::rect(int x, int y, int w, int h)
    {
        PAINTSTRUCT ps = {};
        HDC hDc = ::BeginPaint(m_windowDriver->getHandle(), &ps);

        ::FillRect(hDc, ps.rcPaint, );

        ::EndPaint(m_windowDriver->getHandle(), &ps);
    }

}

