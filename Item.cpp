#include "Item.h"
#include "Character.h"


std::unordered_map<Item::Type, std::string> Item::typeNames = {
	{Type::Ware, "Ware"},
	{Type::Food, "Food"},
	{Type::Weapon, "Weapon"},
	{Type::Armor, "Armor"},
	{Type::Potion, "Potion"},
};

std::unordered_map<Item::Grade, std::string> Item::gradeNames = {
	{Grade::Ordinary, "Ordinary"},
	{Grade::Common, "Common"},
	{Grade::Uncommon, "Uncommon"},
	{Grade::Rare, "Rare"},
	{Grade::Saint, "Saint"},
	{Grade::Heroic, "Heroic"},
	{Grade::King, "King"},
	{Grade::Legendary, "Legendary"},
	{Grade::God, "God"},
};


Item::Item(std::string itemName, Type itemType, Grade itemGrade)
	: itemName(itemName), itemType(itemType), itemGrade(itemGrade)
{
	InitItem();
}

Item::Item(std::string itemName, Type itemType, Grade itemGrade, std::shared_ptr<Character> itemUser)
	: itemName(itemName), itemType(itemType), itemGrade(itemGrade), itemOwner(itemUser)
{
	InitItem();
}

std::shared_ptr<Item> Item::Get()
{
	return std::dynamic_pointer_cast<Item>(Base::Get());
}


std::shared_ptr<Character> Item::GetOwner() const
{
	if (auto weaponUser = itemOwner.lock())
	{
		return weaponUser;
	}

	return nullptr;
}

std::shared_ptr<Character> Item::GetOwner()
{
	if (auto weaponUser = itemOwner.lock())
	{
		return weaponUser;
	}

	return nullptr;
}

void Item::SetOwner(std::shared_ptr<Character> newOwner)
{
	if (auto itemOwner = GetOwner())
	{
		itemOwner->DeleteItem(Get());
	}

	if (newOwner != nullptr)
	{
		itemOwner = newOwner;
		newOwner->AddItem(Get());
	}
}

void Item::Use()
{

}

void Item::Equip()
{

}

void Item::InitItem()
{
	gradeName = gradeNames[itemGrade];
	typeName = typeNames[itemType];
}
