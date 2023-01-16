#include "Person.h"
Person::Person()
{

}
Person::Person(std::string name)
{
	set_name(name);
}
void Person::set_name(std::string name) {
	m_name = name;
}
void Person::set_gender(std::string gender) {
	m_gender = gender;
}
void Person::set_age(std::string age) {
	m_age = age;
}
void Person::add_liked_gift(Gift &gift)
{
	m_liked_gifts.push_back(gift);
}
void Person::select_gender()
{
	std::string gender_response;
	while (true) {
		std::cout << "For which gender should " << get_name() << "'s gift be ?\n";
		std::cout << "Available options: " << "Male | " << "Female | " << "Unisex" << std::endl;
		std::cin >> gender_response;
		if (gender_response == "Male" || gender_response == "male")
		{
			set_gender("Male");
			break;
		}
		else if (gender_response == "Female" || gender_response == "female")
		{
			set_gender("Female");
			break;
		}
		else if (gender_response == "Unisex" || gender_response == "unisex")
		{
			set_gender("Unisex");
			break;
		}
		else
		{
			std::cout << "Input invalid! Incercati inca o data." << std::endl;
		}
	}
}
void Person::select_age()
{
	std::string age_response;
	while (true) {
		std::cout << "What age is " << get_name() << " ?\n";
		std::cout << "Available options: " << "Baby | " << "Child | " << "Teen | " << "Adult | " << "Elder" << std::endl;
		std::cin >> age_response;
		if (age_response == "Baby" || age_response == "baby")
		{
			set_age("Baby");
			break;
		}
		else if (age_response == "Child" || age_response == "child")
		{
			set_age("Child");
			break;
		}
		else if (age_response == "Teen" || age_response == "teen")
		{
			set_age("Teen");
			break;
		}
		else if (age_response == "Adult" || age_response == "adult")
		{
			set_age("Adult");
			break;
		}
		else if (age_response == "Elder" || age_response == "elder")
		{
			set_age("Elder");
			break;
		}
		else
		{
			std::cout << "Input invalid! Incercati inca o data." << std::endl;
		}
	}
}
std::string Person::get_name()
{
	return m_name;
}
std::string Person::get_gender()
{
	return m_gender;
}
std::string Person::get_age()
{
	return m_age;
}
std::vector<Gift> Person::get_liked_gifts()
{
	return m_liked_gifts;
}
std::string Person::to_string() {
	return "Name: " + m_name + ", Gender: " + m_gender + ", Age: " + m_age + ". \n";
}

void Person::matchesGift(Gift& gift)
{
	if (get_gender() == "Male")
	{
		if (gift.get_gender() == "Male" || gift.get_gender() == "Unisex")
			gift.increase_match_score();
	}
	else if (get_gender() == "Female")
	{
		if (gift.get_gender() == "Female" || gift.get_gender() == "Unisex")
			gift.increase_match_score();
	}
	else
		gift.increase_match_score();

	if (gift.get_ages().count(get_age()))
		gift.increase_match_score();
}