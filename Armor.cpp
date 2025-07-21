#include "Armor.h"
#include "Character.h"



Armor::Armor(std::string armorName, Grade armorGrade, std::shared_ptr<Character> armorOwner, int protectionValue)
	: Item(armorName, Type::Armor, armorGrade, armorOwner), protection(protectionValue)
{

}


void Armor::Use()
{

}


void Armor::Equip()
{
	if (auto owner = GetOwner())
	{
		owner->equippedArmor = Get();
	}
}


std::shared_ptr<Armor> Armor::Get()
{
	return std::dynamic_pointer_cast<Armor>(Item::Get());
}

