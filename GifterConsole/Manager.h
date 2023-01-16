#pragma once
#include <iostream>
#include "Person.h"
#include "Watch.h"
#include "ShavingKit.h"
#include "MakeUp.h"
#include <set>

//struct comparator_match_score {
//	bool operator() (const Gift &gift_1, const Gift &gift_2) const {
//			return (gift_1.get_match_score() > gift_2.get_match_score());
//	}
//};

class Manager
{
public:
	Manager();
	void run();
	void match_gifts();
	void select_potential_gifts();
private:

	Person m_person;
	std::vector<Gift> m_all_gifts;
	std::set<Gift> m_potential_gifts;

	Watch m_watch;
	ShavingKit m_shaving_kit;
	MakeUp m_make_up;

};