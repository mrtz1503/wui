#pragma once

namespace wui {

    // every monitor has a ScreenDriver that contains the platform specific screen data

	class Win32ScreenDriver {
	public:

		Win32ScreenDriver();

        void enableDPIAwareness();


	private:



	};



}