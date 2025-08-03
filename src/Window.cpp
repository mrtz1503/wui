#include "wui/Window.h"


namespace wui {

	enum class WindowFlags : long long{
        Visible = 1 << 0,

    };


	struct WindowData {
		int minWidth, minHeight;
		int maxWidth, maxHeight;

        int width, height;
        int x, y;



	};



	



}