#pragma once
#include "Gift.h"
class Doll : public Gift {
public:
	Doll()
	{
		set_name("Doll");
		add_gender("Female");
		add_age("Baby");
		add_age("Child");
		add_age("Teen");
	}
};