#include "wui/SystemDriver.h"

#include "platform/win/Win32_SystemDriver.h"
#include "platform/win/Win32_WindowDriver.h"

#include <memory>
namespace wui {

    std::unique_ptr<SystemDriver> SystemDriver::getNew()
    {
        return std::make_unique<Win32SystemDriver>();
    }

    std::unique_ptr<WindowDriver> WindowDriver::getNew()
    {
        return std::make_unique<Win32_WindowDriver>();
    }
}