#include "Manager.h"

Manager::Manager()
{
	m_all_gifts.push_back(m_watch);
	m_all_gifts.push_back(m_shaving_kit);
	m_all_gifts.push_back(m_make_up);
	m_all_gifts.push_back(m_bag);
	m_all_gifts.push_back(m_bicycle);
	m_all_gifts.push_back(m_belt);
	m_all_gifts.push_back(m_book);
	m_all_gifts.push_back(m_doll);
	m_all_gifts.push_back(m_toy);
	m_all_gifts.push_back(m_sneakers);
	m_all_gifts.push_back(m_plush);
	m_all_gifts.push_back(m_perfume);
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
	recommend_gifts();
	show_liked_gifts();
}

void Manager::match_gifts()
{
	for (auto& gift_to_match : m_all_gifts)
	{
		m_person.matchesGift(gift_to_match);
	}
}

void Manager::select_potential_gifts()
{
	for (const auto& gift_to_insert : m_all_gifts)
	{
		if (gift_to_insert.get_match_score() > 0)
		{
			m_potential_gifts.push_back(gift_to_insert);
			
		}
	}
	std::sort(m_potential_gifts.begin(), m_potential_gifts.end(), comparator_match_score());
	
}

void Manager::recommend_gifts()
{
	for (auto& gift_to_review : m_potential_gifts)
	{
		std::cout << "\n" << "What do you think about: \n \n";
		gift_to_review.print();
		std::string user_input = "";
		std::cin >> user_input;
		if (user_input == "Da" || user_input == "da")
			m_person.add_liked_gift(gift_to_review);
		else if (user_input == "Show" || user_input == "show")
			show_liked_gifts();
	}


	
}

bool Manager::get_review_about_gift()
{

	std::string user_input = "";
	std::cin >> user_input;
	if (user_input == "Da" || user_input == "da")
		return true;
	return false;
}

void Manager::show_liked_gifts()
{
	std::cout << "This are your liked gifts so far:" << std::endl;
	for (auto& liked_gifts : m_person.get_liked_gifts())
		liked_gifts.print();
}
