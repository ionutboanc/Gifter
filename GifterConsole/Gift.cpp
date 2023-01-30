#include "Gift.h"

Gift::Gift()
{
}
Gift::Gift(std::string name)
{
	set_name(name);
}
Gift::Gift(std::string name, std::string gender, std::unordered_set<std::string> ages)
{
	set_name(name);
	add_gender(gender);
	for (const auto& age : ages)
		add_age(age);
}


void Gift::set_name(std::string name)
{
	m_name = name;
}

void Gift::add_gender(std::string gender)
{
	m_gender = gender;
}

void Gift::add_age(std::string age)
{
	m_ages.insert(age);
}

std::string Gift::get_name()
{
	return m_name;
}

std::string Gift::get_nameConst() const
{
	return m_name;
}

std::string Gift::get_gender()
{
	return m_gender;
}

std::unordered_set<std::string> Gift::get_ages()
{
	return m_ages;
}

void Gift::print()
{
	std::cout << "Name: " << get_name() << std::endl;

	std::cout << "Gender: " << get_gender() << std::endl;
	std::cout << "Age(s): " << std::endl;

	for (const auto& age : m_ages) {
		std::cout << "\t" << age << std::endl;
	}
	std::cout << std::endl;
}

void Gift::printConst() const
{
	std::cout << "Name: " << get_nameConst() << std::endl;
}
