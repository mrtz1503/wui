#pragma once

#include <string>
#include "wui/Event.h"



namespace wui {

	class Application {
	public:

		
		void run();


		// returns the complete absolute path of the application
		std::string getFullFileName();
		



	private:


	};

}