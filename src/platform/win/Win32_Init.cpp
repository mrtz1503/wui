#include "wui/SystemDriver.h"

#include "platform/win/Win32_SystemDriver.h"
#include "platform/win/Win32_WindowDriver.h"

#include <memory>

#pragma comment(linker,"\"/manifestdependency:type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")


namespace wui {

    std::unique_ptr<SystemDriver> SystemDriver::getNew()
    {
        return std::make_unique<Win32SystemDriver>();
    }

    std::unique_ptr<WindowDriver> WindowDriver::getNew()
    {
        return std::make_unique<Win32WindowDriver>();
    }
}