#include "Food.h"
#include "Character.h"


Food::Food(std::string foodName, Grade foodGrade, int boost)
	: Item(foodName, Type::Food, foodGrade), vitalsBoost(boost)
{

}


void Food::Use()
{
	if (auto foodOwner = GetOwner())
	{
		foodOwner->BoostVitals(vitalsBoost);
		foodOwner->DeleteItem(Get());
	}
}


void Food::Equip()
{

}


std::shared_ptr<Food> Food::Get()
{
	return std::dynamic_pointer_cast<Food>(Item::Get());
}



