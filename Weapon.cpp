#include "Weapon.h"

DynArr <std::string> Weapon::names;

void Weapon::initNames()
{
	Weapon::names.push("Rock");
	Weapon::names.push("Pocket knive");
	Weapon::names.push("9 mm handgun");
	Weapon::names.push("Crowbar");
	Weapon::names.push("Chainsaw");
	Weapon::names.push("Hunting rifle");
	Weapon::names.push("Assult rifle");
	Weapon::names.push("Face shredder");
	Weapon::names.push("Nail knuckles");
	Weapon::names.push("Crossbow");
	Weapon::names.push("Flamethrower");

};



Weapon::Weapon(int level, std::string name)
	:Item(level, name)
{
	setName(name);
	dmgMax = 1;
	dmgMin = 0;
}
//Copy Constructor
Weapon::Weapon(std::string name, int dmgMin, int dmgMax,
	int lvl, int rarity, int buyValue,	int sellValue) 
	: Item(name, lvl, rarity, buyValue, sellValue)
{
	this->dmgMin = dmgMin;
	this->dmgMax = dmgMax;
}


Weapon::~Weapon()
{
}

Weapon* Weapon::clone() const
{
	return new Weapon(*this);
}


std::string Weapon::toString() const
{
	std::string str =
		getName() + " " +
		std::to_string(getLvl()) + " " +
		std::to_string(getRarity());
	return str;
}
