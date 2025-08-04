#pragma once


#include <Windows.h>
#include <memory>

namespace wui {

	class Window;

	class WindowDriver {
	public:


		static std::shared_ptr<WindowDriver> getNew(std::weak_ptr<Window> window);

		// create a window
		virtual void create() = 0;

		virtual void resize(int x, int y, int cx, int cy) = 0;

	private:

		std::weak_ptr<Window> m_window;
		
	};




}