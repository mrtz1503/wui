#include "platform/win/Win32_SystemDriver.h"

#include "wui/Error.h"
#include <windows.h>
#include <string>
#include <stdexcept>
#include <memory>

namespace wui {


    std::string Win32SystemDriver::getBinFileName()
    {
        return _pgmptr;
    }

    void Win32SystemDriver::displayInfo(const std::string& msg)
    {
        std::string caption = getProcName();
        size_t index = caption.find_last_of('\\');
        caption.erase(caption.begin(), caption.begin() + index + 1);

        ::MessageBoxW(nullptr,
                      utf8ToWideChar(msg).c_str(),
                      utf8ToWideChar(caption).c_str(),
                      MB_OK | MB_ICONINFORMATION);
    }



    void Win32SystemDriver::displayWarning(const std::string& msg)
    {
        std::string caption = getProcName();
        size_t index = caption.find_last_of('\\');
        caption.erase(caption.begin(), caption.begin() + index + 1);
        caption.append(" - Warning! ");

        ::MessageBoxW(nullptr,
                      utf8ToWideChar(msg).c_str(),
                      utf8ToWideChar(caption).c_str(),
                      MB_OK | MB_ICONWARNING);
    }

    void Win32SystemDriver::displayError(const std::string& msg)
    {
        std::string caption = getProcName();
        size_t index = caption.find_last_of('\\');
        caption.erase(caption.begin(), caption.begin() + index + 1);
        caption.append(" - Error! ");

        ::MessageBoxW(nullptr,
                      utf8ToWideChar(msg).c_str(),
                      utf8ToWideChar(caption).c_str(),
                      MB_OK | MB_ICONERROR);
    }



    std::string Win32SystemDriver::getProcName()
    {

        size_t size = MAX_PATH + 1;


        std::wstring procNameW;

        DWORD dwResult = 0;
        do
        {
            std::unique_ptr<wchar_t[]> buf = std::make_unique<wchar_t[]>(size);
            dwResult = ::GetModuleFileNameW(NULL, buf.get(), static_cast<DWORD>(size));
            if (!dwResult)
                throw wui::Error("Failed to get the file name of the application");

            if (dwResult == size)
            {
                size *= 2;
                continue;
            }

            procNameW = std::wstring(buf.get(), buf.get() + dwResult);
            break;
        } while (size < 0xFFFF);

        return Win32SystemDriver::wideCharToUtf8(procNameW);
    }




    std::wstring Win32SystemDriver::utf8ToWideChar(const std::string& str)
    {
        int length = ::MultiByteToWideChar(CP_UTF8, 0, &str[0], static_cast<int>(str.size()), nullptr, 0);
        if (!length)
        {
            throw std::runtime_error("Win32SystemDriver::utf8ToWideChar::MultiByteToWideChar -> Failed while converting");
        }
        size_t size = static_cast<size_t>(length) + 1;
        std::unique_ptr<wchar_t[]> buf = std::make_unique<wchar_t[]>(size);

        ::MultiByteToWideChar(CP_UTF8, 0, &str[0], static_cast<int>(str.size()), buf.get(), static_cast<int>(size));

        return std::wstring(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
    }



    std::string Win32SystemDriver::wideCharToUtf8(const std::wstring& strW)
    {
        int length = ::WideCharToMultiByte(CP_UTF8, 0, &strW[0], static_cast<int>(strW.size()), nullptr, 0, NULL, NULL);
        if (!length)
        {
            throw std::runtime_error("Win32SystemDriver::wideCharToUtf8::WideCharToMultiByte -> Failed while converting");
        }
        size_t size = static_cast<size_t>(length) + 1;
        std::unique_ptr<char[]> buf = std::make_unique<char[]>(size);

        ::WideCharToMultiByte(CP_UTF8, 0, &strW[0], static_cast<int>(strW.size()), buf.get(), static_cast<int>(size), NULL, NULL);

        return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside


    }
}