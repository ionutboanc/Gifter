#pragma once
#include "Gift.h"
class Bicycle : public Gift
{
public:
	Bicycle() {
		set_name("Bicycle");
		add_gender("Unisex");
		add_age("Child");
		add_age("Teen");
		add_age("Adult");
	}
};