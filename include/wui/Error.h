#pragma once

#include <stdexcept>
#include <string>

namespace wui {

    class Error : public std::runtime_error {

    public:
        Error(const std::string& message);

        const char* what() const override;

    private:
        std::string m_msg;
    };

}