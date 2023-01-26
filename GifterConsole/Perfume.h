#pragma once
#include "Gift.h"
class Perfume : public Gift {
public:
Perfume() {
	set_name("Perfume");
	add_gender("Unisex");
	add_age("Teen");
	add_age("Adult");
	}
};