#include "Potion.h"
#include "Character.h"



Potion::Potion(std::string potionName, Grade potionGrade, std::array<int, 3> vitalsBoost)
	: Item(potionName, Type::Potion, potionGrade), vitalsBoost(vitalsBoost)
{

}

void Potion::Use()
{
	if (auto owner = GetOwner())
	{
		owner->ChangeHealth(vitalsBoost[0]);
		owner->ChangeMana(vitalsBoost[1]);
		owner->ChangeStamina(vitalsBoost[2]);
		
		owner->DeleteItem(Get());
	}
}

void Potion::Equip()
{

}

std::shared_ptr<Potion> Potion::Get()
{
	return std::dynamic_pointer_cast<Potion>(Item::Get());
}

