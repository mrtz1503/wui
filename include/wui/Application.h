#pragma once

#include "wui/SystemDriver.h"
#include "wui/Window.h"
#include "wui/Platform.h"

#include <string>
#include <memory>
#include <vector>


namespace wui {

    

    class Application {

        friend class Window;
    public:

        Application();

        static void run();

		static SystemDriver *getSysDriver();
        static std::vector<Window*> m_windows;

        static Window* findWindow(XID id);

    private:

		static std::unique_ptr<SystemDriver> m_sysDriver;
    };

}