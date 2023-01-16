#pragma once
#include "Gift.h"
class Watch : public Gift {
public:
	Watch()
	{
		set_name("Watch");
		add_gender("Male");
		add_age("Teen");
		add_age("Adult");
		add_age("Elder");
	}
};