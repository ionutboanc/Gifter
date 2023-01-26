#pragma once
#include "Gift.h"
class Bag : public Gift
{
public: Bag() {
	set_name("Bag");
	add_gender("Female");
	add_age("Teen");
	add_age("Adult");
}
};