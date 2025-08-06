#pragma once

#include <string>

#include "wui/Utils.h"

#include <utility>
#include <memory>
#include <iostream>

namespace wui {


    class SystemDriver {
    public:


        static std::unique_ptr<SystemDriver> getNew();

        // get the absolute filename of the executable binary
        virtual std::string getBinFileName() = 0;



        template<typename ...Args>
        void displayInfo(const std::string& format, Args...args)
        {
            std::string str = wui::Utils::Format(format, std::forward<Args>(args)...);
            displayInfo(str);
        }
        virtual void displayInfo(const std::string& str) = 0;

        template<typename ...Args>
        void displayWarning(const std::string& format, Args...args)
        {
            std::string str = wui::Utils::Format(format, std::forward<Args>(args)...);
            displayWarning(str);
        }
        virtual void displayWarning(const std::string& str) = 0;

        template<typename ...Args>
        void displayError(const std::string& format, Args...args)
        {
            std::string str = wui::Utils::Format(format, std::forward<Args>(args)...);
            displayError(str);
        }
        virtual void displayError(const std::string& str) = 0;


        virtual std::string getProcName() = 0;


        virtual void pumpMessages() = 0;



    };





}