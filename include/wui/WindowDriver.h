#pragma once

#include <memory>

#include <string>

namespace wui {

	class Window;
	
	class WindowDriver {
	public:
		friend class Window;

		static std::unique_ptr<WindowDriver> getNew();

		Window* getWindow() const;


		virtual void create() = 0;
        




	private:
		void setWindow(Window* window);


		Window *m_window;
	};



}