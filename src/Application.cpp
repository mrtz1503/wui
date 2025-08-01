#include "wui/Application.h"

#include "wui/ApplicationConfig.h"
#include "wui/Error.h"
#include "Definition.h"



#include <Windows.h>

namespace wui {


    void Application::run()
    {

        // run event loop



        std::filesystem::path configFileName = getFullFileName();
        ApplicationConfig config(configFileName.replace_extension(".ini"));
        config.load();
        config.save();
    }



    std::string Application::getFullFileName()
    {

#ifdef WIN32 
        constexpr size_t reserve = MAX_PATH;
#else 
        WUI_ASSERT(false, "Application::getFullFileName is not implemented for this platform");
        constexpr size_t reserve = 0;
#endif 

        std::string filename(reserve, '\0');


#ifdef WIN32
        DWORD dwResult = 0;
        do
        {
            dwResult = ::GetModuleFileNameA(NULL, &filename[0], static_cast<DWORD>(filename.size()));
            if (!dwResult)
                throw wui::Error("Failed to get the file name of the application");

            if (dwResult == filename.size())
            {
                filename.resize(filename.size() * 2);
                continue;
            }

            break;
        } while (filename.size() < 0xFFFF);
        filename.resize(dwResult); // shrink to actual content size;
#endif // WIN32


        WUI_ASSERT(!filename.empty(), "Failed to get the file name of the application");
        return filename;
    }


}