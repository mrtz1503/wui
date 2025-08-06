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

        static void run();
        static SystemDriver* getSysDriver();


    private:

        static std::unique_ptr<SystemDriver> s_sysDriver;
    };

}