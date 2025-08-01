#pragma once

#include <map>
#include <filesystem>

namespace wui {

	class ApplicationConfig {
	public:

		ApplicationConfig(const std::filesystem::path& configFileName)
            : m_filename(configFileName) {}

		bool load();
		bool save();
	
	private:
        std::map<std::string, std::string> m_data;
		std::filesystem::path m_filename;
	};

}