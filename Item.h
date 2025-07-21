#pragma once

#include <unordered_map>
#include <string>
#include "Base.h"


class Character;

class Item : public Base
{

public:

	enum class Type
	{
		Ware = 0, Food, Weapon, Armor, Potion
	};

	enum class Grade 
	{
		Ordinary = 0, Common, Uncommon, Rare, Saint, Heroic, King, Legendary, God
	};

	static std::unordered_map<Type, std::string> typeNames;
	static std::unordered_map<Grade, std::string> gradeNames;


public:

	Item(std::string itemName, Type itemType, Grade itemGrade);
	std::shared_ptr<Item> Get();
	std::shared_ptr<Character> GetOwner() const;
	std::shared_ptr<Character> GetOwner();
	void SetOwner(std::shared_ptr<Character> newOwner);
	virtual void Use();
	virtual void Equip();


public:

	std::string itemName = "UnnamedItem";
	Type itemType = Type::Ware;
	Grade itemGrade = Grade::Common;
	std::weak_ptr<Character> itemOwner;

	std::string gradeName = "Common";
	std::string typeName = "Ware";


private:

	void InitItem();
};
