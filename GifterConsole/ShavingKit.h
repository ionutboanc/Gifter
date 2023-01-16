#pragma once
#include "Gift.h"
class ShavingKit : public Gift {
public:
	ShavingKit()
	{
		set_name("Shaving Kit");
		add_gender("Male");
		add_age("Adult");
		add_age("Elder");
	}
};