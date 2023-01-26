#pragma once
#include "Gift.h"
class Sneakers : public Gift{
public:
	Sneakers() {
		set_name("Sneakers");
		add_gender("Unisex");
		add_age("Child");
		add_age("Teen");
		add_age("Adult");
	}
};