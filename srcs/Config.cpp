#include "../includes/Config.hpp"

//  GETTERS  //
std::string Config::getServerName(void) {return server_name;}
std::string Config::getPortListen(void) {return port_listen;}
std::string Config::getHost(void) {return host;}
std::string Config::getRoot(void) {return root;};
std::string Config::getIndex(void) {return index;}
std::string Config::getErrorPage(void) {return error_page;}
std::string Config::getClientMaxBodySize(void) {return client_max_body_size;}
location_t	*Config::getLocation(void) {return location;}

//  SETTERS  //
void	Config::setServerName(std::string _server_name) {
	int start = _server_name.find(" ");
	int end = _server_name.find(";");
	if (start + 2 >= _server_name.length()) {
		std::cout << "serverName Error" << std::endl;
		return ;
	}
	server_name = _server_name.substr(start + 1, end - start - 1);
	std::cout << ":" << server_name << ":" << std::endl;
}

void	Config::setPortListen(std::string _port_listen) {
	port_listen = _port_listen;
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
	client_max_body_size = _client_max_body_size;
}

void	Config::setLocation(location_t *_location) {
	location = _location;
}

//  METHODS  //
int	Config::searchConfig(std::string option) {
	std::cout << option << std::endl;
	if (option.compare(0, 12, "server_name ") == 0)
		setServerName(option);
	else if (option.compare(0, 7, "listen ") == 0)
		setPortListen(option);
	else if (option.compare(0, 5, "host ") == 0)
		setHost(option);
	else if (option.compare(0, 5, "root ") == 0)
		setRoot(option);
	else if (option.compare(0, 6, "index ") == 0)
		setIndex(option);
	else if (option.compare(0, 11, "error_page ") == 0)
		setErrorPage(option);
	else if (option.compare(0, 5, "client_max_body_size ") == 0)
		setClientMaxBodySize(option);
	else
		return (1);
	return 0;
}

//  EXCEPTIONS  //
/*const char *Config::NotFoundConfigException::what(void) const noexcept{
	const char *error =  "not found";
	return error;
}*/
