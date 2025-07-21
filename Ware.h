#pragma once

#include "Item.h"

class Ware : public Item
{

public:

	Ware(std::string wareName, Grade wareGrade, std::shared_ptr<Character> wareOwner);


	void Use() override;
	void Equip() override;

	std::shared_ptr<Ware> Get();

};


