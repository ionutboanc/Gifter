#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <fstream>

class Gift
{
public:
	Gift();
	Gift(std::string name);
	Gift(std::string name, std::string gender, std::unordered_set <std::string> ages);
	void set_name(std::string name);
	void add_gender(std::string gender);
	void add_age(std::string age);
	std::string get_name();
	std::string get_nameConst() const;
	std::string get_gender();
	std::unordered_set <std::string> get_ages();
	void print();
	void printConst() const;
private:
	std::string m_name;
	std::string m_gender;
	std::unordered_set <std::string> m_ages;

};