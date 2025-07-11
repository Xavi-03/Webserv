#include "../includes/Config.hpp"

//  GETTERS  //
std::string Config::getServerName(void) {return server_name;}
int			Config::getPort(void) {return port;}
std::string Config::getHost(void) {return host;}
std::string Config::getRoot(void) {return root;};
std::string Config::getIndex(void) {return index;}
std::string Config::getErrorPage(void) {return error_page;}
int			Config::getClientMaxBodySize(void) {return client_max_body_size;}
location_t	*Config::getLocation(void) {return iterLocation;}

//  SETTERS  //
void	Config::setServerName(std::string _server_name) {
	server_name = _server_name;
}

void	Config::setPort(std::string _port) {
	std::istringstream value(_port);
	value >> port;
}

void	Config::setHost(std::string _host) {
	host = _host;
}

void	Config::setRoot(std::string _root) {
	root = _root;
}

void	Config::setIndex(std::string _index) {
	index = _index;
}

void	Config::setErrorPage(std::string _error_page) {
	error_page = _error_page;
}

void	Config::setClientMaxBodySize(std::string _client_max_body_size) {
	std::istringstream value(_client_max_body_size);
	value >> client_max_body_size;
}

void	Config::setCgiPath(std::string _cgi_path) {
	cgi_path = _cgi_path;
}

void	Config::setCgiExt(std::string _cgi_ext) {
	cgi_ext = _cgi_ext;
}

void	Config::setLocation(location_t *_location) {
	iterLocation = _location;
}

//  METHODS  //
std::string	Config::takeParams(std::string option, int *error) {
	int start = option.find(" ");
	int end = option.find(";");
	if (end == -1 || start == -1) {
		std::cout << GREEN << "Error: found at \"" << option << "\"" << RESET << std::endl;
		*error = 1;
		return "Error";
	}
	//std::cout << start << std::endl;
	//std::cout << end << std::endl;
	return option.substr(start + 1, end - start - 1);
}


int	Config::searchConfig(std::string option) {
	int error = 0;
	//std::cout << option << std::endl;
	if (option.compare(0, 12, "server_name ") == 0)
		setServerName(takeParams(option, &error));
	else if (option.compare(0, 7, "listen ") == 0)
		setPort(takeParams(option, &error));
	else if (option.compare(0, 5, "host ") == 0)
		setHost(takeParams(option, &error));
	else if (option.compare(0, 5, "root ") == 0)
		setRoot(takeParams(option, &error));
	else if (option.compare(0, 6, "index ") == 0)
		setIndex(takeParams(option, &error));
	else if (option.compare(0, 11, "error_page ") == 0)
		setErrorPage(takeParams(option, &error));
	else if (option.compare(0, 21, "client_max_body_size ") == 0)
		setClientMaxBodySize(takeParams(option, &error));
	else if (option.compare(0, 0, "cgi_path"))
		setCgiPath(takeParams(option, &error));
	else if (option.compare(0, 0, "cgi_ext"))
		setCgiExt(takeParams(option, &error));
	else if (option.compare(0, 9, "location ") == 0)
		addLocation();
	else {
		std::cout << GREEN << "Error not found: " << option << RESET << std::endl;
		return 1;
	}
	if (error)
		return 1;
	return 0;
}

void	Config::printConfig(void) {
	std::cout << "server name: " << server_name << std::endl;
	std::cout << "port listen: " << port << std::endl;
	std::cout << "host: " << host << std::endl;
	std::cout << "root: " << root << std::endl;
	std::cout << "index: " << index << std::endl;
	std::cout << "error page: " << error_page << std::endl;
	std::cout << "client max body size: " << client_max_body_size << std::endl;
}

int	Config::checkRoot(void) {
	if (access(root.data(), F_OK))
		return (1);
	return (0);
}

//  EXCEPTIONS  //
/*const char *Config::NotFoundConfigException::what(void) const noexcept{
	const char *error =  "not found";
	return error;
}*/
//  LINKED LIST LOCATIONS  //
location_t *Config::addLocation(void) {
	location_t *tmpLocation = new location_t;
	if (!firstLocation) {
		firstLocation = tmpLocation;
		iterLocation = tmpLocation;
		lastLocation = tmpLocation;
	}
	lastLocation->next = tmpLocation;
	tmpLocation->next = NULL;
	// set default values
	lastLocation = tmpLocation;
	return tmpLocation;
}
