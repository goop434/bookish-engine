#ifndef ITEM_H
#define ITEM_H
#include <string>
#include "DynArr.h"

class Item
{
private:
	std::string name;
	int lvl;
	int rarity;
	double buyValue;
	double sellValue;
public:
	Item(int level, std::string name);
	//Copy Constructor
	Item(std::string name = "NONE", int level = 0,
		int rarity = 0,
		int bvalue = 0,
		int svalue = 0);
	virtual ~Item();

	//Functions
	virtual Item* clone()const = 0;
	virtual std::string toString() const = 0;

	//Accessors
	inline const std::string& getName() const { return name; }
	inline const int& getLvl() const { return lvl; }
	inline const int& getRarity() const { return rarity; }
	inline const double& getBuyValue() const { return buyValue; }
	inline const double& getSellValue() const { return sellValue; }

	//Modifiers
	void setName(std::string name) { this->name = name; }
	//Static

};

enum { common = 0, uncommon, rare, legendary, mythic };
#endif // !ITEM_H
