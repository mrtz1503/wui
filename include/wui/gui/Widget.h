#pragma once

#include <set>

#include "wui/EventHandler.h"

namespace wui {

    // Base class for every thing that can be drawn on screen
    class Widget : public EventHandler {
    public:


        enum Flag {
            Visible = 1 << 0,
            Resizable = 1 << 1,
            Fullscreen = 1 << 2,
            Maximized = 1 << 3,
            Minimized = 1 << 4,

            FramedWindow = 1 << 16,

        };



        void addFlag(Flag flag) { m_flags.insert(flag); }
        bool hasFlag(Flag flag) const { return m_flags.count(flag); }



    private:

        std::set<Flag> m_flags;
    };


}