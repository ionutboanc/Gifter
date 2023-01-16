#pragma once

#include <iostream>
#include <string>
#include "Gift.h"
#include <vector>
class Person
{
public:
	Person();
	Person(std::string name);
	void set_name(std::string name);
	void set_gender(std::string gender);
	void set_age(std::string age);
	void add_liked_gift(Gift &gift);
	void select_gender();
	void select_age();
	std::string get_name();
	std::string get_gender();
	std::string get_age();
	std::vector<Gift> get_liked_gifts();
	std::string to_string();

	void matchesGift(Gift &gift);

private:
	std::string m_name;
	std::string m_gender;
	std::string m_age;
	std::vector<Gift> m_liked_gifts;

};