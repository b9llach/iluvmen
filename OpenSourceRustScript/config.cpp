#include "config.h"

namespace fs = std::filesystem;
using namespace std;

int config::load_config(std::string file_path)
{
	std::fstream f(file_path.append(".mw"));
	if (!f.is_open()) {
		std::cout << "[load_config] Could not open config '" + file_path + "'\n";
	}
	else {
		std::string line;
		while (getline(f, line)) {
			//line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
			if (line[0] == '#' || line.empty())
				continue;
			auto delimiterPos = line.find("=");
			auto name = line.substr(0, delimiterPos);
			auto value = line.substr(delimiterPos + 1);
			settings[name] = stof(value);
		}
	}
	return 0;
}

int config::save_config(std::string file_path, std::map<std::string, int> settings)
{	
	std::ofstream f(file_path.append(".mw"));
	if (!f.is_open()) {
		std::cout << "[save_config] Could not open config '" + file_path + "'\n";
	}
	else {
		for (auto const& [key, val] : settings)
		{
			f << key << "=" << val << endl;
		}
	}
	return 0;
}
