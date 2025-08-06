#include <wui/wui.h>
#include <iostream>

int main()
{
    try
    {
        wui::FramedWindow fw;
        wui::
        fw.add();
        fw.show();

        wui::Application::run();
    }
    catch (const std::exception& e)
    {
        wui::Application::getSysDriver()->
            displayError("%s, %s",
                         "An unhandled error occured while running the application : \n\t",
                         e.what());

        exit(EXIT_FAILURE);
    }

    return 0;
}