#pragma once

#include <string>
#include <Windows.h>
#include <memory>

#include "wui/gui/Widget.h"

namespace wui {

    class Window;

    class WindowDriver {
    public:
        friend class Window;

        static std::unique_ptr<WindowDriver> getNew();

        Window* getWindow() const;

        virtual void create() = 0;
        virtual void destroy() = 0;
        virtual bool created() = 0;

        // flags of window changed
        virtual void flags(const std::set<Widget::Flag>& flags) = 0;

        virtual void resize(int x, int y, int width, int height) = 0;

    private:
        void setWindow(Window* window);

        Window* m_window; // pointer to window that contains this driver
    };




}