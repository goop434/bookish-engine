#include "Armor.h"


DynArr <std::string> Armor::headArmors;
DynArr <std::string> Armor::bodyArmors;
DynArr <std::string> Armor::feetArmors;

void Armor::initNames()
{
	//Head
	Armor::headArmors.push("Safety Goggles");
	Armor::headArmors.push("Hazmat hood");
	Armor::headArmors.push("Gas mask");
	Armor::headArmors.push("Riot helmet");
	Armor::headArmors.push("Motorcycle helmet");
	Armor::headArmors.push("Army helmet");
	Armor::headArmors.push("Power armor helmet");

	//Body
	Armor::bodyArmors.push("Lab coat");
	Armor::bodyArmors.push("Jumpsuit");
	Armor::bodyArmors.push("Trench coat");
	Armor::bodyArmors.push("Bullet-resistant vest");
	Armor::bodyArmors.push("Makeshift plate armor");
	Armor::bodyArmors.push("Power Armor");
	Armor::bodyArmors.push("Hazmat suit");

	//Feet
	Armor::feetArmors.push("Dress shoes");
	Armor::feetArmors.push("sneakers");
	Armor::feetArmors.push("boots");
	Armor::feetArmors.push("Army boots");
	Armor::feetArmors.push("Power armor boots");

}



Armor::Armor(int lvl, std::string name)
	:Item(lvl, name)
{
	defRating = 1;
	type = 0;
	if (type = 0)
		setName(Armor::headArmors[rand() % Armor::headArmors.size() - 1]);
	else if (type = 1)
	setName(Armor::bodyArmors[rand() % Armor::bodyArmors.size() - 1]);
	else if (type = 2)
		setName(Armor::feetArmors[rand() % Armor::feetArmors.size() - 1]);
}

Armor::Armor(std::string name, int lvl, int rarity,
	int buyValue, int sellValue, int defR, int slot)
	: Item(name, lvl, rarity, buyValue, sellValue)
{
	defRating = defR;
	this->type = slot;
}


Armor::~Armor()
{
}

Armor* Armor::clone() const
{
	return new Armor(*this);
}


std::string Armor::toString() const
{
	std::string str = 
		getName() + " " +
		std::to_string(getLvl()) + " " +
		std::to_string(getRarity()) + " " +
		std::to_string(type) + "-" + 
		std::to_string(defRating);
	return str;
}