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
#include <algorithm>


//struct comparator_match_score {
//	bool operator() (const Gift &gift_1, const Gift &gift_2) const {
//			return (gift_1.get_match_score() > gift_2.get_match_score());
//	}
//};

class Manager
{
public:
	Manager();

	//void handle_user();
	void create_new_person();
	void see_previous_persons();
	void menu_beginning();
	//void menu_wrong_password(std::string user_name);
	//void menu_user_not_found(std::string user_name);
	void run();
	void match_gifts();
	void select_potential_gifts();
	void recommend_gifts();
	bool get_review_about_gift();
	void show_liked_gifts();
private:
	
	Person m_person;
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
	User m_user;
};