#include "wui/gui/FramedWindow.h"

#include "wui/Event.h"

namespace wui {


    FramedWindow::FramedWindow()
    {
        addFlag(Flag::FramedWindow);
        setSize(640, 480);

        map(Event::Create, this, &FramedWindow::onCreate);
    }

    bool FramedWindow::onCreate(CreateEvent& event)
    {
        (void)event;

        return true;
    }





}