#pragma once
#include "Gift.h"
class Book : public Gift{
public:
	Book()
	{
		set_name("Book");
		add_gender("Unisex");
		add_age("Child");
		add_age("Teen");
		add_age("Adult");
		add_age("Elder");
	}
};