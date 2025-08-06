# include "platform/win/Win32_ScreenDriver.h"

#include <Windows.h>

namespace wui {

    Win32ScreenDriver::Win32ScreenDriver()
    {
        enableDPIAwareness();

    }

    void Win32ScreenDriver::enableDPIAwareness()
    {
        ::SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
    }



}