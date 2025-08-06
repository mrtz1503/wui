#pragma once

#include "wui/SystemDriver.h"

#include <string>
#include <Windows.h>

namespace wui {

    class Win32SystemDriver : public SystemDriver {
    public:

        virtual std::string getBinFileName() override;

        virtual std::string getProcName() override;

        virtual void displayInfo(const std::string& str) override;
        virtual void displayWarning(const std::string& str) override;
        virtual void displayError(const std::string& str) override;



        virtual void pumpMessages() override;

        

        static std::wstring utf8ToWideChar(const std::string& str);
        static std::string wideCharToUtf8(const std::wstring& strW);


        static bool hasClass(const std::wstring& name);

        static HINSTANCE getInst()
        {
            return s_hInst;
        }

    private:


        static HINSTANCE s_hInst;
    };

}
