#pragma once

#include <string>
#include <Windows.h>
#include <memory>

namespace wui {

	class Window;
	
	class WindowDriver {
	public:
		friend class Window;

		static std::unique_ptr<WindowDriver> getNew();

		Window* getWindow() const;


		virtual void create() = 0;
		virtual void resize(int x, int y, int cx, int cy) = 0;
        


	private:
		void setWindow(Window* window);

    Window *m_window;		
	};




}