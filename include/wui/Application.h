#pragma once

#include "wui/SystemDriver.h"

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

namespace wui {

    

    class Window;
    class WindowDriver;

    class Application {

        friend class Window;
        friend class WindowDriver;

    public:

        Application();

        static void run();

		static SystemDriver *getSysDriver();
        static std::vector<Window*> m_windows;


    private:

        static Window* findWindow(WindowDriver* drv);
        static std::unordered_map<Window*, WindowDriver*> m_windows;

		static std::unique_ptr<SystemDriver> m_sysDriver;
    };

}