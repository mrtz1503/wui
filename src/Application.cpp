#include "wui/Application.h"

#include "wui/ApplicationConfig.h"
#include "wui/Error.h"
#include "Definition.h"

#include "wui/SystemDriver.h"


#include <Windows.h>

namespace wui {


    std::unique_ptr<SystemDriver> Application::m_sysDriver = SystemDriver::getNew();

    void Application::run()
    {

        // run event loop


    }



    SystemDriver *Application::getSysDriver()
    {
        return m_sysDriver.get();
    }


}