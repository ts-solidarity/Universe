#pragma once
#include "Item.h"

class Food : public Item
{

public:


	Food(std::string foodName, Grade foodGrade, std::shared_ptr<Character> foodOwner, int boost);


	void Use() override;
	void Equip() override;
	
	std::shared_ptr<Food> Get();


public:

	int vitalsBoost = 0;

};
