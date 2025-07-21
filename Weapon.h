#pragma once

#include "Item.h"

class Character;

class Weapon : public Item
{

public:

	Weapon(std::string weaponName, Grade weaponGrade, int baseAttack, int baseDefence);
	std::shared_ptr<Weapon> Get();

	void Use() override;
	void Equip() override;

public:

	int baseAttack = 0;
	int baseDefence = 0;

};


