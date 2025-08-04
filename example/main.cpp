#include <wui/wui.h>
#include <iostream>

int main()
{
    try
    {
        wui::FramedWindow fw;
        fw.show();
        
        wui::Application::run();
    }
    catch (const std::exception& e)
    {
        std::string msg = "An unhandled error occured while running the application: \n\t";
        msg.append(e.what());

        wui::Application::getSysDriver()->displayError(msg);
        std::cerr << e.what() << std::endl;;
        exit(EXIT_FAILURE);
    }

    return 0;
}