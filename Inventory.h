#ifndef INVENTORY_H
#define INVENTORY_H
#include "Weapon.h"
#include "Armor.h"
#include <iostream>

class Inventory
{
private:
	int capacity;
	int numItems;
	Item** itemArr;

	void expand();
	void initialize(const int from = 0);

public:
	Inventory();
	~Inventory();
	Inventory(const Inventory& obj);
	Item& operator[](const int index);
	inline int size() const { return numItems; }
	void addItem(const Item& item);
	void removeItem(int index);
};


#endif // !INVENTORY_H
