#pragma once

#include <vector>
#include <string>
#include "Base.h"

class Weapon;
class Armor;
class Item;

typedef std::vector<std::shared_ptr<Item>> ItemList;


class Character : public Base
{

public:

	enum class Gender
	{
		Male = 0, Female
	};


public:

	Character(
		std::string name, Gender gender,
		int age, int health, int mana, int stamina,
		int xp, int level
	);

	std::shared_ptr<Character> Get();

	std::shared_ptr<Item> FindItemFromInventory(std::shared_ptr<Item> item);
	std::shared_ptr<Item> FindItemFromInventory(int uniqueId);
	bool IsInInventory(std::shared_ptr<Item> item);
	bool IsInInventory(int uniqueId);
	void AddItem(std::shared_ptr<Item> item);
	void DeleteItem(std::shared_ptr<Item> item);

	void Equip(std::shared_ptr<Item> item);
	void Use(std::shared_ptr<Item> item);

	void BoostVitals(int amount);

	void ChangeAge(int amount);
	void ChangeHealth(int amount);
	void ChangeMana(int amount);
	void ChangeStamina(int amount);
	void ChangeXp(int amount);
	void ChangeLevel(int amount);


public:

	std::string name = "Unnamed";
	Gender gender = Gender::Female;
	int age = 20;
	int health = 100;
	int mana = 100;
	int stamina = 100;
	int xp = 0;
	int level = 1;
	std::shared_ptr<Weapon> equippedWeapon = nullptr;
	std::shared_ptr<Armor> equippedArmor = nullptr;
	ItemList inventory{};
};
