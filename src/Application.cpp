#include "wui/Application.h"

#include "wui/ApplicationConfig.h"
#include "wui/Error.h"
#include "Definition.h"

#include "wui/SystemDriver.h"


#include <Windows.h>

namespace wui {



    void Application::run()
    {

        // run event loop


    }



    SystemDriver *Application::getSysDriver()
    {
        return m_sysDriver.get();
    }


}