#pragma once

#include "Person.h"
#include <direct.h>
#include <sys/stat.h>
class User
{
public:
	User();
	User(std::string name, std::string password);
	User(std::string name, std::string password, std::vector<Person> persons);
	bool check_if_user_exists(std::string user_name);
	void sign_up(std::string user_name);
	bool log_in(std::string user_name);
	void set_user_name(std::string user_name);
	void set_password(std::string password);
	std::string get_user_name();
	std::string get_password();
private:
	std::string m_user_name;
	std::string m_password;
	std::vector<Person> m_persons;
};