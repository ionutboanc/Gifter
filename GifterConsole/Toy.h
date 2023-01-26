#pragma once
#include "Gift.h"
class Toy : public Gift{
public:

	Toy() {
		set_name("Toy");
		add_gender("Unisex");
		add_age("Baby");
		add_age("Child");
	}
};