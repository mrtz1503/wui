#include "wui/SystemDriver.h"

#ifdef WIN32 
#include "platform/win/Win32_SystemDriver.h"
#include "platform/win/Win32_WindowDriver.h"

#include <Windows.h>
#include <memory>

namespace wui {

    std::unique_ptr<SystemDriver> SystemDriver::getNew()
    {
        return std::make_unique<Win32SystemDriver>();
    }

    std::unique_ptr<WindowDriver> WindowDriver::getNew()
    {
        return std::make_unique<Win32WindowDriver>();
    }


    // xid typedef for hwnd
    typedef ::HWND xid;

}

#else 

namespace wui {

    std::unique_ptr<SystemDriver> SystemDriver::getNew()
    {
        return nullptr; // Not implemented for non-Windows platforms
    }
    std::unique_ptr<WindowDriver> WindowDriver::getNew()
    {
        return nullptr; // Not implemented for non-Windows platforms
    }
    // xid typedef for some other platform-specific window handle type
    typedef void* xid; // Placeholder, replace with actual type as needed

}

#endif
