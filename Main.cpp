#include <iostream>

#include "Character.h"

#include "Ware.h"
#include "Food.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"



int main()
{
	auto izroth = std::make_shared<Character>("Izroth", Character::Gender::Male, 
		25, 120, 75, 140, 0, 1);
	
	auto ordinarySword = std::make_shared<Weapon>("Ordinary Sword", Item::Grade::Ordinary,
		20, 5);

	auto ordinaryArmor = std::make_shared<Armor>("Ordinary Armor", Item::Grade::Ordinary, 15);

	izroth->AddItem(ordinarySword);
	izroth->AddItem(ordinaryArmor);

	izroth->Equip(ordinarySword);
	izroth->Equip(ordinaryArmor);
}

