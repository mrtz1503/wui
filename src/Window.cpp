#include "wui/Window.h"

#include "wui/WindowDriver.h"
#include "wui/Application.h"

namespace wui {

	enum class WindowFlags : long long{
        Visible = 1 << 0,

    };




	Window::Window()
	{
		m_driver = WindowDriver::getNew();
        m_driver->setWindow(this);
	}


	void Window::show()
	{


	}

  Window::~Window()
    {
    }
	



}