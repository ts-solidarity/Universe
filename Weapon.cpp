#include "Weapon.h"
#include "Character.h"

Weapon::Weapon(std::string weaponName, Grade weaponGrade, int baseAttack, int baseDefence, std::shared_ptr<Character> weaponOwner)
	: Item(weaponName, Type::Weapon, weaponGrade, weaponOwner), baseAttack(baseAttack), baseDefence(baseDefence)
{

}


std::shared_ptr<Weapon> Weapon::Get()
{
	return std::dynamic_pointer_cast<Weapon>(Item::Get());
}

void Weapon::Use()
{

}

void Weapon::Equip()
{
	auto owner = GetOwner();
	if (owner) {
		owner->equippedWeapon = Get();
	}
}
