#pragma once

#include "Item.h"



class Armor : public Item
{

public:

	Armor(std::string armorName, Grade armorGrade, std::shared_ptr<Character> armorOwner, int protectionValue);

	void Use() override;
	void Equip() override;

	std::shared_ptr<Armor> Get();



public:

	int protection = 0;

};
 