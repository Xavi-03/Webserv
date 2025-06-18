#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <iostream>
# include <cstdlib>
# include <unistd.h>

# define GREEN "\x1B[32m"
# define RESET "\x1B[0m"


struct location_t {
	std::string		allow_methods[3];
	struct Location	*next;
};

class Config {
private:
	std::string	server_name;
	//std::string ip_listen;
	std::string	port_listen;
	std::string	host;
	std::string	root;
	std::string	index;
	std::string	error_page;
	std::string	client_max_body_size;

	location_t	*location;
//  METHODS  //
	std::string	takeParams(std::string option, int *error);
public:
//  GETTERS  //
	std::string getServerName(void);
	std::string getPortListen(void);
	std::string getHost(void);
	std::string getRoot(void);
	std::string getIndex(void);
	std::string getErrorPage(void);
	std::string getClientMaxBodySize(void);
	location_t	*getLocation(void);
	//  SETTERS  //
	void	setServerName(std::string _server_Name);
	void	setPortListen(std::string _port_listen);
	void	setHost(std::string _host);
	void	setRoot(std::string _root);
	void	setIndex(std::string _index);
	void	setErrorPage(std::string error_page);
	void	setClientMaxBodySize(std::string _client_max_body_size);
	void	setLocation(location_t *_location);
//  METHODS  //
	int		searchConfig(std::string option);
	void	printConfig(void);
	int		checkRoot(void);



//  EXCEPTIONS  //
/*class NotFoundConfigException : public std::exception {
public:
	virtual const char* what() const noexcept;
};*/

};

#endif
