#pragma once

#include <array>
#include "Item.h"


class Potion : public Item
{

public:

	Potion(std::string potionName, Grade potionGrade, std::array<int, 3> vitalsBoost);
	
	void Use() override;
	void Equip() override;

	std::shared_ptr<Potion> Get();

public:


	std::array<int, 3> vitalsBoost{0, 0, 0};

};
