#pragma once

#include <set>

#include "wui/EventHandler.h"

namespace wui {



    /**
    * @brief Base class for every thing that can be drawn on screen
    */
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


        virtual void addFlag(Flag flag) { m_flags.insert(flag); }
        virtual void removeFlag(Flag flag) { m_flags.erase(flag); }
        bool hasFlag(Flag flag) const { return m_flags.count(flag); }
        const std::set<Flag>& getFlags() const { return m_flags; }


        int getX() const { return m_x; }
        int getY() const { return m_y; }
        int getWidth() const { return m_width; }
        int getHeight() const { return m_height; }

        virtual void setSize(int width, int height) { m_width = width; m_height = height; };
        virtual void setPos(int x, int y) { m_x = x; m_y = y };


    private:

        std::set<Flag> m_flags;


        // position
        int m_x = 0;
        int m_y = 0;

        // width
        int m_width = 0;
        int m_minWidth = 0;
        int m_maxWidth = 0;

        // height
        int m_height = 0;
        int m_minHeight = 0;
        int m_maxHeight = 0;



    };


}