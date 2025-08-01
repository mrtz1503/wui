#include "wui/ApplicationConfig.h"


#include <filesystem>
#include <fstream>
#include <string>


namespace wui {
    bool ApplicationConfig::load()
    {
        std::ifstream stream(m_filename);
        if (!(stream.good() || stream.eof()))
            return false;

        for (std::string line; std::getline(stream, line);)
        {
            bool inQuotes = false;
            bool escaped = false;

            if (line.empty() || line[0] == ';')
                continue;

            for (size_t i = 0; i < line.size(); i++)
            {

                switch (line[i])
                {
                    case '\\':
                        escaped = true; // Escape the next character
                        break;

                    case '"':
                        if (!escaped)
                        {
                            inQuotes = !inQuotes;
                        }

                        break;

                    case '=':
                        if (!inQuotes)
                        {
                            m_data.emplace(
                                std::string(line.begin(), line.begin() + i),
                                std::string(line.begin() + i + 1, line.end()));
                        }
                        break;

                    default:
                        escaped = false;
                }
            }
        }

        if(stream.fail())
            return false;

        return true;
    }




    bool ApplicationConfig::save()
    {
    
        
        return true;
    }





} // namespace wui
