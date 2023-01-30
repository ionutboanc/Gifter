#include "User.h"
User::User()
{

}

User::User(std::string name, std::string password)
{
	m_name = name;
	m_password = password;
}
User::User(std::string name, std::string password, std::vector<Person> persons)
{
	m_name = name;
	m_password = password;
	m_persons = persons;
}

bool User::check_if_user_exists(std::string user_name)
{
	struct stat sb;
	std::string adress = "./" + user_name;
	if (stat(adress.c_str(), &sb) == 0)
	{
		m_user_name = user_name;
		return true;
	}
	return false;
}
void User::sign_up(std::string user_name)
{
	std::string password;
	std::string adress = "./" + user_name;
	_mkdir(adress.c_str());
	std::cout << "Oh so you're new here! Enter a secret password that you'll remember: ";
	std::cin >> password;
	m_password = password;
	std::ofstream passwordFile(user_name + "/" + password + ".txt");
	passwordFile.close();
	
}
bool User::log_in(std::string user_name)
{
	std::string password;
	std::cout << "Welcome back! Enter your password: ";
	std::cin >> password;
	std::ifstream ifs("./" + user_name + "/" + password + ".txt");
	if (ifs.good())
	{
		std::cout << "Logged in." << std::endl;
		m_password = password;
		return true;
	}
	else
	{
		std::cout << "Wrong password!" << std::endl;
		return false;
		
	}
}

void User::set_user_name(std::string user_name)
{
	m_user_name = user_name;
}

void User::set_password(std::string password)
{
	m_password = password;
}

std::string User::get_user_name()
{
	return m_user_name;
}

std::string User::get_password()
{
	return m_password;
}

