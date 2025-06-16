
#include <iostream>
#include <fstream>
#include <string>
#include "../includes/Config.hpp"

void	takeConfig(std::string configFile) {
	std::ifstream	configFd;
	std::string 	line;
	std::string		tmp;
	Config			*config[5] = {NULL, NULL, NULL, NULL, NULL};

	configFd.open(configFile.data(), std::ifstream::in);
	int	j = -1;
	while(std::getline(configFd, line)) {
		tmp.clear();
		if (line.empty())
			continue ;
		for (int i = 0; i < line.length(); i++) {
			if ((tmp.empty()) && (line[i] == ' ' || line[i] == '\t'))
				continue ;
			tmp.push_back(line[i]);
		}
		if (tmp == "server") {
			config[++j] = new Config;
			continue ;
		}
		if (j == -1) // Error not found sercer {}
			return ;
		else if (tmp[0] == '{' || tmp[0] == '}')
			continue ; //handle brackets open and closed
		config[j]->searchConfig(tmp);
	}


	configFd.close();
}



int main(int argc, char **argv) {
	if (argc != 2) {
		return 1;
	}
	takeConfig(argv[1]);

	return 0;
}
