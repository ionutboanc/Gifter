#pragma once
#include "Gift.h"
class Plush : public Gift{
public:
	Plush() 
	{
		set_name("Plush");
		add_gender("Unisex");
		add_age("Child");
		add_age("Teen");
	}
};