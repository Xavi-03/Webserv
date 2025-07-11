#ifndef CONFIG_HPP
# define CONFIG_HPP

# include <iostream>
# include <cstdlib>
# include <unistd.h>
# include <sstream>

# define GREEN "\x1B[32m"
# define RESET "\x1B[0m"



class Location {
private:
	std::string directory;
	bool GET;
	bool POST;
	bool DELETE;

public:

};

struct location_t {
	Location *Location = NULL;
	struct location_t	*next = NULL;
};

class Config {
private:
	std::string	server_name;
	//std::string ip_listen;
	int			port;
	std::string	host;
	std::string	root;
	std::string	index;
	std::string	error_page;
	int			client_max_body_size;
	bool		cgi;
	std::string	cgi_path;
	std::string	cgi_ext;
	location_t	*firstLocation;
	location_t	*iterLocation;
	location_t	*lastLocation;
//  METHODS  //
	std::string	takeParams(std::string option, int *error);
public:
//  GETTERS  //
	std::string getServerName(void);
	int getPort(void);
	std::string getHost(void);
	std::string getRoot(void);
	std::string getIndex(void);
	std::string getErrorPage(void);
	int getClientMaxBodySize(void);
	location_t	*getLocation(void);
	//  SETTERS  //
	void	setServerName(std::string _server_Name);
	void	setPort(std::string _port);
	void	setHost(std::string _host);
	void	setRoot(std::string _root);
	void	setIndex(std::string _index);
	void	setErrorPage(std::string error_page);
	void	setClientMaxBodySize(std::string _client_max_body_size);
	void	setLocation(location_t *_location);
	void	setCgiPath(std::string _cgi_path);
	void	setCgiExt(std::string _cgi_ext);
//  METHODS  //
	int		searchConfig(std::string option);
	void	printConfig(void);
	int		checkRoot(void);



//  EXCEPTIONS  //
/*class NotFoundConfigException : public std::exception {
public:
	virtual const char* what() const noexcept;
};*/


//  LINEKED LIST LOCATIONS //
location_t	*addLocation(void);
};

#endif
