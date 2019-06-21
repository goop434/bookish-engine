#include "Item.h"



Item::Item(int level, std::string name)
{
	this-> name = name;
	lvl = level;
	rarity = 1;
	buyValue = rarity * 50.00;
	sellValue = buyValue / 2;
}

//Copy constructor
Item::Item(std::string name, int lvl, int rarity, 
	int bvalue , int svalue)
{
	this->name = name;
	this->lvl = lvl;
	this->rarity = rarity;
	buyValue = bvalue;
	sellValue = svalue;
}


Item::~Item()
{
}
