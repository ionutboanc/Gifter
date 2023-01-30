#pragma once

#include "Person.h"
struct User
{
	std::string m_user_name;
	std::string m_password;
	std::vector<Person> m_persons;
	int m_index_current_person = 0;
};