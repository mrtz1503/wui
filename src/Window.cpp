#include "wui/Window.h"

#include "wui/WindowDriver.h"
#include "wui/Application.h"

namespace wui {



    Window::Window()
    {
        Application::s_windows.insert(this);

        m_drv = WindowDriver::getNew();
        m_drv->setWindow(this);

    }


    void Window::show()
    {
        if (!isVisible())
        {
            m_drv->create();
            addFlag(Flag::Visible);
        }
    }






}