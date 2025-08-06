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
        if (!m_drv->created())
            m_drv->create();

        if (!visible())
            addFlag(Flag::Visible);
    }

    void Window::hide()
    {
        removeFlag(Flag::Visible);
    }

    void Window::close()
    {

        m_drv->destroy();
    }

    void Window::setSize(int width, int height)
    {
        Widget::setSize(width, height);
        m_drv->resize(getX(), getY(), width, height);
    }


}