#include "wui/Window.h"

#include "wui/WindowDriver.h"
#include "wui/Application.h"

namespace wui {

	enum class WindowFlags : long long{
        Visible = 1 << 0,

    };




    Window::Window()
    {

        Application::registerWindow(this);
       
    }


    Window::~Window()
    {
        Application::unregisterWindow(this);
    }
	



}