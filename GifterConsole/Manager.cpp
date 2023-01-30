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

	handle_user();
}

void Manager::menu_wrong_password(std::string user_name)
{
	std::cout << "Do you want to: " << std::endl;
	std::cout << "1. Try again." << std::endl;
	std::cout << "2. Go back." << std::endl;
	int choice;
	std::cin >> choice;
	if (choice == 1)
		if (m_user.log_in(user_name) == true)
			run();
		else
			menu_wrong_password(user_name);
	else if (choice == 2)
		handle_user();
	else
	{
		std::cout << "Invalid input!" << std::endl;
		menu_wrong_password(m_user.get_user_name());
	}
}
void Manager::menu_user_not_found(std::string user_name)
{
	std::cout << "1. A new User." << std::endl;
	std::cout << "2. An existing user who entered his user name wrong." << std::endl;
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		m_user.sign_up(user_name);
		run();
	}
	else if (choice == 2)
		handle_user();
	else
	{
		std::cout << "Invalid input!" << std::endl;
		menu_user_not_found(user_name);
	}

}
void Manager::handle_user()
{
	std::string user_name;
	std::cout << "Hallo! Welcome to Gifter.\n";
	std::cout << "Enter your user name: ";
	std::cin >> user_name;
	std::cout << std::endl;


	if (m_user.check_if_user_exists(user_name) == true)
		if (m_user.log_in(user_name) == true)
			run();
	else
	{
		std::cout << "This user name was not found! Are you:" << std::endl;
		menu_user_not_found(user_name);
	}
}
void Manager::create_new_person()
{
	std::string name;
	std::cout << "What is the name of the lucky person ?\n";
	std::cin >> name;
	m_person.set_name(name);
	m_person.select_gender();
	m_person.select_age();

	std::cout << m_person.to_string();

	match_gifts();
	recommend_gifts();
	show_liked_gifts();
}
void Manager::see_previous_persons()
{

}
void Manager::menu_beginning()
{
	std::cout << "What do you want to do ?" << std::endl;
	std::cout << "1. Select a gift for a new person." << std::endl;
	std::cout << "2. See previous persons I've researched gift ideas about." << std::endl;
	int choice;
	std::cin >> choice;
	if (choice == 1)
		create_new_person();
	else if (choice == 2)
		see_previous_persons();
	else
	{
		std::cout << "Invalid input!" << std::endl;
		menu_beginning();
	}
}
void Manager::run()
{
	menu_beginning();
}

void Manager::match_gifts()
{
	for (auto& gift_to_match : m_all_gifts)
	{
		if (m_person.filterGift(gift_to_match) == true)
			m_potential_gifts.push_back(gift_to_match);
	}
	std::random_shuffle(std::begin(m_potential_gifts), std::end(m_potential_gifts));
}

void Manager::select_potential_gifts()
{
	/*for (const auto& gift_to_insert : m_all_gifts)
	{
		if (gift_to_insert.get_match_score() > 0)
		{
			m_potential_gifts.push_back(gift_to_insert);

		}
	}*/
	//std::sort(m_potential_gifts.begin(), m_potential_gifts.end(), comparator_match_score());

}

void Manager::recommend_gifts()
{
	system("cls");
	for (std::size_t i = 0; i < m_potential_gifts.size(); i++)
	{
		Gift gift_to_review = m_potential_gifts.at(i);
		std::cout << "What do you think about: \n \n";
		gift_to_review.print();
		std::cout << "(Yes/Show) \n \n";
		std::string user_input = "";
		std::cin >> user_input;
		if (user_input == "Yes" || user_input == "yes")
			m_person.add_liked_gift(gift_to_review);
		else if (user_input == "Show" || user_input == "show")
		{
			show_liked_gifts();
			i--;
		}
		system("cls");
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
	system("cls");

	if (m_person.get_liked_gifts().size() > 0)
	{
		std::cout << "These are your liked gifts so far:" << std::endl;
		for (auto& liked_gifts : m_person.get_liked_gifts())
			liked_gifts.print();
	}
	else
		std::cout << "Oops! You haven't liked any gift yet." << std::endl;

	std::cout << "Enter any key to go back to reviewing gift ideas!" << std::endl;
	std::cin.ignore();
	std::cin.get();
}
