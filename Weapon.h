#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
#include <sstream>
#include <string>
class Weapon : public Item
{
private:
	int dmgMin;
	int dmgMax;
public:
	Weapon(int lvl, std::string name);
	//Copy Constructor
	Weapon(std::string name = "NONE", int dmgMin = 0, int dmgMax = 0,
		int lvl = 0,
		int rarity = 0,
		int buyValue = 0,
		int sellValue = 0);
	virtual ~Weapon();

	virtual Weapon* clone() const;

	int getDmgMin() const { return dmgMin; }
	int getDmgMax() const { return dmgMax; }


	std::string toString() const;

	//Static
	static DynArr <std::string> names;
	static void initNames();

};

#endif // !WEAPON_H
