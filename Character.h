#ifndef CHARACTER_H
#define CHARACTER_H
#include "Inventory.h"
#include "Enemy.h"

class Character
{
private:
	std::string name;
	int lvl;
	int exp;
	int expNext;
	int hp;
	int hpMax;
	int stamina;
	int staminaMax;
	int def;
	int dmgMax;
	int dmgMin;
	int statPoints;
	int str, per, vit;

	int floor;

	double hitChance, critChance;
	double money;

	Inventory inventory;
	Weapon weapon;
	Armor armor_Head;
	Armor armor_Body;
	Armor armor_Feet;


public:
	Character();

	//Accessors
	std::string getName() const { return name; }
	int getLvl() const { return lvl; }
	int getExp() const { return exp; }
	int getExpNext() const { return expNext; }
	int getHp() const { return hp; }
	int getHpMax() const { return hpMax; }
	int getStamina() const { return stamina; }
	int getStaminaMax() const { return staminaMax; }
	int getDef() const { return def; }
	int getDmgMin() const { return dmgMin; }
	int getDmgMax() const { return dmgMax; }
	int getStatPoints() const { return statPoints; }
	int getStr() const { return str; }
	int getPer() const { return per; }
	int getVit() const { return vit; }
	int getFloor() const { return floor; }
	double getHitChance() const { return hitChance; }
	double getCritChance() const { return critChance; }
	double getMoney() const { return money; }

	Inventory getInv() const { return inventory; }
	Weapon getWep() const { return weapon; }
	Armor getHeadArmor() const { return armor_Head; }
	Armor getBodyArmor() const { return armor_Body; }
	Armor getFeetArmor() const { return armor_Feet; }


	int getDamage()const { return rand() % (dmgMax-dmgMin + 1) + dmgMin; }

	//Modifiers
	void takeDamage(int dmg) { hp -= dmg; }
	bool loseStamina(int amount) 
	{ 
		if (stamina <= 0)
		{
			stamina = 0;
			return false;
		}
		stamina -= amount;
		return true;
	}
	void addItem(const Item& item) { inventory.addItem(item); }

	//Operators
	void operator= (const Character& obj);

	//Functions
	void Initialize(std::string name, int lvl = 1, int exp = 0, int statpoints = 0,
		int hp = 100, int stamina = 100, int str = 5, int per = 5, int vit = 5,
		int floor = 0);
	void lvlUp();
	void updateStats();
	std::string printStats() const;
	void gainExp(int exp);
	std::string toString() const;
	bool isAlive() { return hp > 0; }
	void rest();
	std::string invToString();
};

#endif // !CHARACTER_H
