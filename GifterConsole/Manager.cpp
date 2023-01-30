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
bool Manager::check_if_user_exists(std::string& user_name)
{
	struct stat sb;
	std::string adress = "./" + user_name;
	if (stat(adress.c_str(), &sb) == 0)
	{
		return true;
	}
	return false;
}
void Manager::sign_up()
{
	std::string adress = "./" + m_user.m_user_name;
	_mkdir(adress.c_str());
	std::cout << "Oh so you're new here! Enter a secret password that you'll remember: ";
	std::cin >> m_password;
	std::ofstream passwordFile(m_user.m_user_name + "/" + m_password + ".txt");
	passwordFile.close();
	m_user.m_index_current_person = 0;
	create_new_person();

}
void Manager::log_in()
{
	std::cout << "Welcome back! Enter your password: ";
	std::cin >> m_password;
	std::ifstream ifs("./" + m_user.m_user_name + "/" + m_password + ".txt");
	if (ifs.good())
	{
		std::cout << "Logged in." << std::endl;
		std::string person_name;
		while (std::getline(ifs, person_name)) {
			Person person;
			std::ifstream personGiftStream("./" + m_user.m_user_name + "/" + person_name + ".txt");

			std::string person_gift_data;
			while (std::getline(personGiftStream, person_gift_data))
				for(auto& gift : m_all_gifts)
					if(person_gift_data == gift.get_name())
				person.add_liked_gift(gift);
			std::ifstream personStream("./" + m_user.m_user_name + "/" + person_name + ".txt");
			personStream >> person;
			
			
			m_user.m_persons.push_back(person);
		}
		m_user.m_index_current_person = m_user.m_persons.size() - 1;
		run();
	}
	else
	{
		std::cout << "Wrong password!" << std::endl;
		menu_wrong_password();

	}
}
void Manager::menu_wrong_password()
{
	std::cout << "Do you want to: " << std::endl;
	std::cout << "1. Try again." << std::endl;
	std::cout << "2. Go back." << std::endl;
	int choice;
	std::cin >> choice;
	if (choice == 1)
		log_in();
	else if (choice == 2)
		handle_user();
	else
	{
		std::cout << "Invalid input!" << std::endl;
		menu_wrong_password();
	}
}
void Manager::menu_user_not_found()
{
	std::cout << "1. A new User." << std::endl;
	std::cout << "2. An existing user who entered his user name wrong." << std::endl;
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		sign_up();
	}
	else if (choice == 2)
		handle_user();
	else
	{
		std::cout << "Invalid input!" << std::endl;
		menu_user_not_found();
	}

}
void Manager::handle_user()
{
	system("cls");
	std::string user_name;
	std::cout << "Hallo! Welcome to Gifter.\n";
	std::cout << "Enter your user name: ";
	std::cin >> user_name;
	std::cout << std::endl;
	m_user.m_user_name = user_name;
	try {

		if (check_if_user_exists(user_name) == true)
			log_in();
		else
		{
			throw m_ue;
			
		}
	}
	catch (UserNotFoundException ue)
	{
		std::cout<<ue.what()<<std::endl;
		std::cout << "Are you:" << std::endl;
		menu_user_not_found();
	}
}
void Manager::create_new_person()
{
	system("cls");
	Person person;
	std::string name;
	std::cout << "What is the name of the lucky person ?\n";
	std::cin >> name;
	person.set_name(name);
	person.select_gender();
	person.select_age();
	m_user.m_persons.push_back(person);
	std::ofstream passwordFile(m_user.m_user_name + "/" + m_password + ".txt", std::ofstream::app);
	passwordFile << name << std::endl;
	passwordFile.close();
	std::ofstream new_person_stream(m_user.m_user_name + "/" + name + ".txt");
	new_person_stream << person;
	new_person_stream.close();

	match_gifts();
	recommend_gifts();
	menu_beginning();
}

void Manager::menu_previous_persons()
{
	system("cls");

	for (size_t i = 0; i < m_user.m_persons.size(); i++)
	{
		Person person = m_user.m_persons.at(i);
		std::cout << i + 1 << ". " << person.to_string() << std::endl;
	}

	std::cout << "Enter index of person to select it or 0 to go back. " << std::endl;

	size_t choice;
	std::cin >> choice;
	if (choice == 0)
		menu_beginning();
	else
	{
		if (choice > 0 && choice <= m_user.m_persons.size())
		{
			m_user.m_index_current_person = choice - 1;
			match_gifts();
			recommend_gifts();
			show_liked_gifts();
			menu_beginning();
		}
		else {
			std::cout << "Invalid input!" << std::endl;
			menu_previous_persons();
		}
	}
}
void Manager::menu_beginning()
{
	std::cout << "What do you want to do ?" << std::endl;
	std::cout << "1. Select a gift for a new person." << std::endl;
	std::cout << "2. See previous persons I've researched gift ideas about." << std::endl;
	int choice;
	std::cin >> choice;
	if (choice == 1)
	{
		m_user.m_index_current_person = m_user.m_index_current_person + 1;
		create_new_person();
	}
	else if (choice == 2)
		menu_previous_persons();
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
	m_potential_gifts.clear();
	for (auto& gift_to_match : m_all_gifts)
	{
		if (m_user.m_persons.at(m_user.m_index_current_person).filterGift(gift_to_match) == true)
			m_potential_gifts.push_back(gift_to_match);
	}
	std::random_shuffle(std::begin(m_potential_gifts), std::end(m_potential_gifts));
}


void Manager::recommend_gifts()
{
	system("cls");
	std::ofstream person_stream(m_user.m_user_name + "/" + m_user.m_persons.at(m_user.m_index_current_person).get_name() + ".txt", std::ofstream::app);
	Person current_person = m_user.m_persons.at(m_user.m_index_current_person);
	for (std::size_t i = 0; i < m_potential_gifts.size(); i++)
	{
		Gift gift_to_review = m_potential_gifts.at(i);
		bool the_same = false;
		std::ifstream personGiftStream("./" + m_user.m_user_name + "/" + current_person.get_name() + ".txt");

		std::string person_gift_data;
		while (std::getline(personGiftStream, person_gift_data))
			if (person_gift_data == gift_to_review.get_name())
			{
				the_same = true;
			}
		if (the_same == false)
		{
			std::cout << "Do you think " << current_person.get_name() << " would like this: \n \n";
			gift_to_review.print();
			std::cout << "(Yes/Show) \n \n";
			std::string user_input = "";
			std::cin >> user_input;
			if (user_input == "Yes" || user_input == "yes")
			{
				current_person.add_liked_gift(gift_to_review);
				person_stream << gift_to_review.get_name() << std::endl;
			}
			else if (user_input == "Show" || user_input == "show")
			{

				show_liked_gifts();
				i--;
			}
			personGiftStream.close();

			system("cls");
		}
	}
	person_stream.close();


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
	Person current_person = m_user.m_persons.at(m_user.m_index_current_person);
	
	if (current_person.get_liked_gifts().size() > 0)
	{
		std::cout << "These are your liked gifts so far:" << std::endl;
		for (auto& liked_gifts : current_person.get_liked_gifts())
			liked_gifts.print();
	}
	else
		std::cout << "Oops! You haven't liked any gift yet." << std::endl;

	std::cout << "Enter any key to go back to reviewing gift ideas!" << std::endl;
	std::cin.ignore();
	std::cin.get();
}
