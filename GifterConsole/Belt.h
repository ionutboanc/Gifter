#pragma once
#include "Gift.h"
class Belt : public Gift
{
public: Belt() {
	set_name("Belt");
	add_gender("Male");
	add_age("Teen");
	add_age("Adult");
	add_age("Elder");
}
};