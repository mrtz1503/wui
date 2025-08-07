#pragma once

#include "wui/SystemDriver.h"

#include <string>
#include <memory>
#include <set>

namespace wui {


    class Window;
    class WindowDriver;

    class Application {

        friend class Window;
        friend class WindowDriver;

    public:

        void run();
        SystemDriver* getSystemDrviver();
        ScreenDriver* getScreenDrviver();



    private:


        std::unique_ptr<SystemDriver> m_systemDriver;
        std::unique_ptr<ScreenDriver> m_screenDriver;

    };

}