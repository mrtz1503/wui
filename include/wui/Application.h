#pragma once

#include "wui/SystemDriver.h"

#include <string>
#include <memory>



namespace wui {


	
	class Application {
	public:
		
		static void run();


		
		static SystemDriver *getSysDriver();

	private:

		static std::unique_ptr<SystemDriver> m_sysDriver;
	};

}