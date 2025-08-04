#include "wui/SystemDriver.h"

#include "platform/win/Win32_SystemDriver.h"
#include "platform/win/Win32_WindowDriver.h"
#include <memory>
namespace wui {

    std::shared_ptr<SystemDriver> SystemDriver::getNew()
    {
        return std::make_shared<Win32SystemDriver>();
    }


    std::shared_ptr<WindowDriver> WindowDriver::getNew(std::weak_ptr<Window> window)
    {
        return std::make_shared<Win32WindowDriver>(window);
    }
}