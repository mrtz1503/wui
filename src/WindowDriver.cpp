#include "wui/WindowDriver.h"

namespace wui {


    void WindowDriver::setWindow(Window* window)
    {
        m_window = window;
    }

    Window *WindowDriver::getWindow() const
    {
        return m_window;
    }



}