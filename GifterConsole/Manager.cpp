#include "Manager.h"

Manager::Manager()
{
	m_all_gifts.push_back(m_watch);
	m_all_gifts.push_back(m_shaving_kit);
	m_all_gifts.push_back(m_make_up);
}

void Manager::run()
{
	std::string name;
	std::cout << "Hallo! Welcome to Gifter, what is the name of the lucky person ?\n";
	std::cin >> name;
	m_person.set_name(name);
	m_person.select_gender();
	m_person.select_age();

	std::cout << m_person.to_string();

	match_gifts();
	select_potential_gifts();
	
}

void Manager::match_gifts()
{

	m_person.matchesGift(m_all_gifts.at(0));
	m_person.matchesGift(m_all_gifts.at(1));
	m_person.matchesGift(m_all_gifts.at(2));
}

void Manager::select_potential_gifts()
{
	for (const auto& gift_to_insert : m_all_gifts)
	{
		if (gift_to_insert.get_match_score() > 0)
		{
			m_potential_gifts.insert(gift_to_insert);
			
		}
	}

	for (auto& gift_to_print : m_potential_gifts)
	{
		gift_to_print.printConst();
	}
}