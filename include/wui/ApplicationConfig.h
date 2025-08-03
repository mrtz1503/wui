#pragma once

#include <map>
#include <string>

namespace wui {

	class ApplicationConfig {
	public:

		ApplicationConfig(const std::string& configFileName)
            : m_filename(configFileName) {}

		bool load();
		bool save();
	
	private:
        std::map<std::string, std::string> m_data;
		std::string m_filename;
	};

}