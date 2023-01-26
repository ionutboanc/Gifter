#pragma once
#include "Gift.h"
class Flowers : public Gift{
public:
	Flowers() {
		set_name("Flowers");
		add_gender("Female");
		add_age("Child");
		add_age("Teen");
		add_age("Adult");
		add_age("Elder");
	}
};