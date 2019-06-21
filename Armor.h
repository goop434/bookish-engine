#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include <sstream>
#include <string>

enum ArmorType {Head = 0, Body, Feet};

class Armor : public Item
{
private:
	int defRating;
	int type;
public:
	Armor(int lvl, std::string name);
	Armor(std::string name = "NONE", int lvl = 0, int rarity = 0, 
		int buyValue = 0, int sellValue = 0, int defR = 0, int slot = 0);
	virtual ~Armor();

	virtual Armor* clone() const;

	std::string toString() const;

	int getDef() const { return defRating; }
	int getType() const { return type; }

	//Static
	static DynArr <std::string> headArmors;
	static DynArr <std::string> bodyArmors;
	static DynArr <std::string> feetArmors;
	static void initNames();
};

#endif // !ARMOR_H
