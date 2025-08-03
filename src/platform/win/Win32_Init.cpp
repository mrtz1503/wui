#include "wui/SystemDriver.h"

#include "platform/win/Win32_SystemDriver.h"

namespace wui {

    SystemDriver& SystemDriver::getNew()
    {
        static Win32SystemDriver localSysDriver;
        return localSysDriver;
    }

}