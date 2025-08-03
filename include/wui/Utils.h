#pragma once

#include <string>


namespace wui {
    namespace Utils {

        template<typename ... Args>
        std::string Format(const std::string& format, Args ... args)
        {
            //WUI_ASSERT(format.empty(), "Why call this function without a format specified?");

            int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
            if (size_s <= 0)
            {
                throw std::runtime_error("Error during formatting.");
            }
            size_t size = static_cast<size_t>(size_s);
            std::unique_ptr<char[]> buf = std::make_unique<char[]>(size);
            std::snprintf(buf.get(), size, format.c_str(), args ...);
            return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside

        }

    }
}