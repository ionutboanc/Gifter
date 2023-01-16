#pragma once
#include "Gift.h"

class MakeUp : public Gift
{
public:
	MakeUp()
	{
		set_name("Make Up");
		add_gender("Female");
		add_age("Teen");
		//add_age("Adult");
	}
};