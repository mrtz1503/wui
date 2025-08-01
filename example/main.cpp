#include <wui/wui.h>
#include <iostream>

int main()
{
    try
    {
        wui::Application app;
        app.run();
        std::cout << app.getFullFileName() << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << "An unhandled error occurred while running the application: \n\t" << e.what() << std::endl;;
    }

    return 0;
}