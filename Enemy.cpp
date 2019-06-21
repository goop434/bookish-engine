#include "Enemy.h"

Enemy::Enemy()
{
	this->name = "NONE";
	this->hpMax = 0;
	this->armor = 0;
	this->dmgMin = 0;
	this->dmgMax = 0;
	this->accuracy = 0;
	this->pursuit = 0;
	this->expReward = 0;
	this->difficultyRating = 0;
}

Enemy::~Enemy()
{
}

std::string Enemy::toString() const
{
	return "Name:" + name + "\nDifficulty Rating: " + std::to_string(difficultyRating)
		+ "\nHp: " + std::to_string(hp) + " / " + std::to_string(hpMax)
		+ "\nDamage: " + std::to_string(dmgMin) + "-" + std::to_string(dmgMax)
		+ "\nArmor: " + std::to_string(armor)
		+ "\nAccuracy: " + std::to_string(accuracy)
		+ "\nPursuit: " + std::to_string(pursuit)
		+ "\nExp Reward: " + std::to_string(expReward);

}

void Enemy::printItemPool() const
{
	if (itemPool.empty())
	{
		std::cout << "Drops: nothing\n\n";
		return;
	}

	std::cout << "Drops: \n";
	for (int i = 0; i < itemPool.size(); i++)
	{
		std::cout << itemPool[i].first << ": " << itemPool[i].second << "% chance\n";
	}
	std::cout << std::endl;
}

void Enemy::takeDamage(int dmg)
{
	hp -= dmg; //FIXME: implent armor mechanic

	if (hp <= 0)
	{

	}
}

void Enemy::initialize(std::string name, int hpMax, int armor, int dmgMin,
	int dmgMax, int acc, int pur, int exp, int dRating,
	std::vector <std::pair<std::string, int>> drops)
{
	this->name = name;
	this->hpMax = hpMax;
	this->armor = armor;
	this->dmgMin = dmgMin;
	this->dmgMax = dmgMax;
	this->accuracy = acc;
	this->pursuit = pur;
	this->expReward = exp;
	this->difficultyRating = dRating;

	for (size_t i = 0; i < drops.size(); i++)
	{
		itemPool.push_back(drops[i]);
	}
	
	hp = hpMax;
}