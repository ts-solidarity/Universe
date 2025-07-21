#include "Ware.h"

Ware::Ware(std::string wareName, Grade wareGrade)
	: Item(wareName, Type::Ware, wareGrade)
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
