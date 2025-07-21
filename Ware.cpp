#include "Ware.h"

Ware::Ware(std::string wareName, Grade wareGrade, std::shared_ptr<Character> wareOwner)
	: Item(wareName, Type::Ware, wareGrade, wareOwner)
{

}


std::shared_ptr<Ware> Ware::Get()
{
	return std::dynamic_pointer_cast<Ware>(Item::Get());
}


void Ware::Use()
{

}

void Ware::Equip()
{

}
