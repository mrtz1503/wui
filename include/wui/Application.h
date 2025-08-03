#pragma once

#include "wui/SystemDriver.h"

#include <string>



namespace wui {


	
	class Application {
	public:
		
		void run();


		
		static SystemDriver& getSysDriver();

	private:

	};

}