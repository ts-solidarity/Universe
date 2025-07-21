#include <algorithm>
#include "Character.h"
#include "Item.h"


Character::Character(
	std::string name, Gender gender,
	int age, int health, int mana, int stamina,
	int xp, int level
)
	: name(name), gender(gender), age(age), health(health),
	mana(mana), stamina(stamina), xp(xp), level(level)
{

}


std::shared_ptr<Character> Character::Get()
{
	return std::dynamic_pointer_cast<Character>(Base::Get());
}

std::shared_ptr<Item> Character::FindItemFromInventory(std::shared_ptr<Item> item)
{
	auto ownedItem = std::find_if(
		inventory.begin(), inventory.end(),
		[&](const std::shared_ptr<Item>& i)
		{
			return i->GetUniqueId() == item->GetUniqueId();
		}
	);

	if (ownedItem != inventory.end())
	{
		return *ownedItem;
	}

	return nullptr;
}

std::shared_ptr<Item> Character::FindItemFromInventory(int uniqueId)
{
	auto ownedItem = std::find_if(
		inventory.begin(), inventory.end(),
		[&](const std::shared_ptr<Item>& i)
		{
			return i->GetUniqueId() == uniqueId;
		}
	);

	if (ownedItem != inventory.end())
	{
		return *ownedItem;
	}

	return nullptr;
}

bool Character::IsInInventory(std::shared_ptr<Item> item)
{
	return std::find_if(
		inventory.begin(), inventory.end(),
		[&](const std::shared_ptr<Item>& i)
		{
			return i->GetUniqueId() == item->GetUniqueId();
		}
	) != inventory.end();
}

bool Character::IsInInventory(int uniqueId)
{
	return std::find_if(
		inventory.begin(), inventory.end(),
		[&](const std::shared_ptr<Item>& i)
		{
			return i->GetUniqueId() == uniqueId;
		}
	) != inventory.end();
}

void Character::AddItem(std::shared_ptr<Item> item)
{
	inventory.emplace_back(item);
}

void Character::DeleteItem(std::shared_ptr<Item> item)
{
	inventory.erase(
		std::remove_if(
			inventory.begin(), inventory.end(), 
			[&](const std::shared_ptr<Item>& i)
			{
				return i->GetUniqueId() == item->GetUniqueId();
			}
		), 
		inventory.end());
}

void Character::Equip(std::shared_ptr<Item> item)
{
	if (IsInInventory(item))
	{
		item->Equip();
	}
}

void Character::Use(std::shared_ptr<Item> item)
{
	if (IsInInventory(item))
	{
		item->Use();
	}
}

void Character::BoostVitals(int amount)
{
	ChangeHealth(amount);
	ChangeMana(amount);
	ChangeStamina(amount);
}

void Character::ChangeAge(int amount)
{
	age += amount;
}

void Character::ChangeHealth(int amount)
{
	health += amount;
}

void Character::ChangeMana(int amount)
{
	mana += amount;
}

void Character::ChangeStamina(int amount)
{
	stamina += amount;
}

void Character::ChangeXp(int amount)
{
	xp += amount;
}

void Character::ChangeLevel(int amount)
{
	level += amount;
}
