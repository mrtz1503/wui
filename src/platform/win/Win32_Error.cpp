#include "platform/win/Win32_Error.h"

#include <stdexcept>
#include <Windows.h>
#include <string>

namespace wui {


    const char* Error::what() const 
    {
        return m_msg.c_str();
    }

    Error::Error(const std::string& message) : std::runtime_error(message)
    {
        m_msg = std::runtime_error::what();
        DWORD dwLastError = ::GetLastError();

        LPSTR lpstrMessageBuffer = nullptr;
        DWORD dwSize = ::FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                        NULL,
                                        dwLastError,
                                        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                                        (LPSTR)&lpstrMessageBuffer,
                                        0,
                                        NULL);



        m_msg.append("\n\tWin32 Error: \n\tCode: ");
        m_msg.append(std::to_string(
            static_cast<unsigned long>(
                ::GetLastError())));
        m_msg.append("\n\tMessage: ");
        m_msg.append(lpstrMessageBuffer, static_cast<unsigned long>(dwSize));

        ::LocalFree(lpstrMessageBuffer);
    }

}
