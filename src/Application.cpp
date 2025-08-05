#include "wui/Application.h"

#include "wui/ApplicationConfig.h"
#include "wui/Error.h"
#include "Definition.h"

#include "wui/SystemDriver.h"

#include <Windows.h>

namespace wui {

    std::unique_ptr<SystemDriver> Application::s_sysDriver = SystemDriver::getNew();
    std::set<Window*> Application::s_windows;

    void Application::run()
    {

        // run event loop

        while (Application::s_windows.size() > 0) { s_sysDriver->pumpMessages(); };
    }



    SystemDriver* Application::getSysDriver()
    {
        return s_sysDriver.get();
    }


}