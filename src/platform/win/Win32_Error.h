#include "wui/Error.h"

namespace wui {
    
    
    class Win32Error : public Error {
    public:
        Win32Error() : Error("Win32 Error") {}
        Win32Error(const std::string& message) : Error(message) {}
        virtual const char* what() const override {
            return Error::what();
        }
    };


} // namespace wui