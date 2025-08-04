#pragma once

#include "wui/SystemDriver.h"
#include "wui/Window.h"

#include <string>
#include <memory>
#include <vector>


namespace wui {


    class Application {

        friend class Window;
    public:

        Application();


        static void run();



        static std::shared_ptr<SystemDriver> getSysDriver();

    private:

        static void registerWindow(Window *window);
        static void unregisterWindow(Window *window);


		static SystemDriver *getSysDriver();
        static std::vector<Window*> m_windows;
        static std::shared_ptr<SystemDriver> s_sysDriver;

		static std::unique_ptr<SystemDriver> m_sysDriver;
    };

}