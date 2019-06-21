#include "Inventory.h"



Inventory::Inventory()
{
	capacity = 5;
	numItems = 0;
	itemArr = new Item*[capacity];
	initialize();
}

Inventory::~Inventory()
{
	for (int i = 0; i < capacity; i++)
	{
		delete[] itemArr[i];
	}
	delete[] itemArr;
}

Inventory::Inventory(const Inventory& obj)
{
	this->capacity = obj.capacity;
	this->numItems = obj.numItems;
	this->itemArr = new Item*[this->capacity];

	for (size_t i = 0; i < this->numItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	initialize(this->numItems);
}

Item& Inventory::operator[](const int index)
{
	if (index < 0 || index >= numItems)
		throw ("BAD INDEX!");
	return *this->itemArr[index];
}

void Inventory::expand()
{
	capacity *= 2;
	Item** tempArr = new Item*[capacity];

	for (int i = 0; i < numItems; i++)
	{
		tempArr[i] = itemArr[i];
	}
	
	delete[] itemArr;

	itemArr = tempArr;
	initialize(numItems);
}

void Inventory::initialize(const int from)
{
	for (int i = from; i < capacity; i++)
	{
		itemArr[i] = nullptr;
	}
}

void Inventory::addItem(const Item& item)
{
	if (numItems >= capacity)
	{
		std::cout << "Inventory Full" << std::endl;
		expand();
		itemArr[numItems++] = item.clone();
	}
	else
	{
		itemArr[numItems++] = item.clone();
	}
}

void Inventory::removeItem(int index)
{

}