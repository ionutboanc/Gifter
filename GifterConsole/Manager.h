#pragma once
#include <iostream>
#include "Person.h"
#include "Watch.h"
#include "ShavingKit.h"
#include "MakeUp.h"
#include "Bag.h"
#include "Bicycle.h"
#include "Belt.h"
#include "Book.h"
#include "Doll.h"
#include "Flowers.h"
#include "Perfume.h"
#include "Toy.h"
#include "Sneakers.h"
#include "Plush.h"
#include "User.h"
#include "UserNotFoundException.h"
#include <algorithm>
#include <fstream>
#include <direct.h>
#include <sys/stat.h>
//struct comparator_match_score {
//	bool operator() (const Gift &gift_1, const Gift &gift_2) const {
//			return (gift_1.get_match_score() > gift_2.get_match_score());
//	}
//};

class Manager
{
public:
	Manager();

	bool check_if_user_exists(std::string& user_name);
	void log_in();
	void sign_up();
	void handle_user();
	void create_new_person();
	void menu_previous_persons();
	void menu_beginning();
	void menu_wrong_password();
	void menu_user_not_found();
	void run();
	void match_gifts();
	void recommend_gifts();
	bool get_review_about_gift();
	void show_liked_gifts();
private:
	struct User m_user;
	struct UserNotFoundException m_ue;
	std::string m_password;
	std::vector<Gift> m_all_gifts;
	std::vector<Gift> m_potential_gifts;

	Bag m_bag;
	Belt m_belt;
	Bicycle m_bicycle;
	Book m_book;
	Doll m_doll;
	Perfume m_perfume;
	Plush m_plush;
	Sneakers m_sneakers;
	Toy m_toy;
	Watch m_watch;
	ShavingKit m_shaving_kit;
	MakeUp m_make_up;

};