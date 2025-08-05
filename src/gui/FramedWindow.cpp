#include "wui/gui/FramedWindow.h"

#include "wui/Event.h"

namespace wui {


    FramedWindow::FramedWindow()
    {
        addFlag(Flag::FramedWindow);

        map(Event::Create, FramedWindow::onCreate);
    }

    bool FramedWindow::onCreate(CreateEvent &event)
    {
        (void)event;

        return true;
    }





}