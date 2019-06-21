#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>

class Enemy
{
private:
	std::string fileName;
	std::string name;
	int lvl;
	int hp, hpMax;
	int dmgMin, dmgMax;
	int armor;
	int accuracy;
	int expBase;
	int expReward;
	int pursuit;
	int difficultyRating;
	std::vector <std::pair<std::string, int>> itemPool;

public:
	Enemy();
	void initialize(std::string name, int hpMax, int armor, int dmgMin,
		int dmgMax, int acc, int pur, int exp, int dRating, 
		std::vector <std::pair<std::string, int>> drops);
	virtual ~Enemy();

	int getDRating() const { return difficultyRating; }
	std::string getName() const { return name; }
	int getLvl() const { return lvl; }
	int getHp() const { return hp; }
	int getHpMax() const { return hpMax; }
	int getAccuracy() const { return accuracy; }
	int getPursuit() const { return pursuit; }

	int attack()const { return rand() % (dmgMax-dmgMin+1)+dmgMin; }
	int dropExp() { return expReward; }
	void dropItem()
	{

	}


	inline bool isAlive() { return hp > 0; }
	void takeDamage(int dmg);

	std::string toString() const;
	void printItemPool() const;
};

#endif // !ENEMY_H