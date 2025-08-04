#include <wui/wui.h>
#include <iostream>

int main()
{

    wui::MainWindow exampleWindow;
    exampleWindow.show();



    try
    {
        wui::Application::run();
    }
    catch (const std::exception& e)
    {
        std::string msg = std::string("An unhandled error occured while running the application: \n\t")
            + std::string(e.what());

        wui::Application::getSysDriver()->displayError(msg);
        ::exit(EXIT_FAILURE);
    }

    return 0;
}