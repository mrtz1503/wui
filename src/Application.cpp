#include "wui/Application.h"

#include "wui/ApplicationConfig.h"
#include "wui/Error.h"
#include "Definition.h"

#include "wui/SystemDriver.h"


#include <Windows.h>

namespace wui {


    std::shared_ptr<SystemDriver> Application::s_sysDriver;


    Application::Application()
    {
        s_sysDriver = SystemDriver::getNew();
    }

    void Application::run()
    {

        // run event loop





    }



    std::shared_ptr<SystemDriver> Application::getSysDriver()
    {
        return s_sysDriver;
    }


}