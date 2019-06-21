#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Character.h"

Character::Character()
{
	lvl = 0;
	exp = 0;
	expNext = 0;
	hpMax = 0;
	hp = hpMax;
	def = 0;
	dmgMax = 0;
	dmgMin = 0;
	statPoints = 0;
	str = 0;
	per = 0;
	vit = 0;

	floor = 0;

	hitChance = 0.0;
	critChance = 0.0;
	money = 0.0;
}

void Character::operator= (const Character& obj)
{
	this->name = obj.getName();
	this->lvl = obj.getLvl();
	this->exp = obj.getExp();
	this->expNext = obj.getExpNext();
	this->hp = obj.getHp();
	this->hpMax = obj.getHpMax();
	this->stamina = obj.getStamina();
	this->staminaMax = obj.getStaminaMax();
	this->def = obj.getDef();
	this->dmgMax = obj.getDmgMax();
	this->dmgMin = obj.getDmgMin();
	this->statPoints = obj.getStatPoints();
	this->str = obj.getStr();
	this->per = obj.getPer();
	this->vit = obj.getVit();
	this->floor = obj.getFloor();
	this->hitChance = obj.getHitChance();
	this->critChance = obj.getCritChance();
	this->money = obj.getMoney();

	//FIXME, OR DON'T,THIS WAS PROBABLY A STUPID IDEA ANYWAY: copy Items
}

void Character::Initialize(std::string name, int lvl, int exp, int statpoints,
	int hp,	int stamina, int str, int per, int vit, int floor)
{
	this->name = name;
	this->lvl = lvl;
	this->exp = exp;
	expNext = static_cast <int>
		((50 / 3)*(pow(lvl, 3) -
			6 * pow(lvl, 2) +
			(17 * lvl) - 12) + 96);

	this->statPoints = statpoints;
	this->str = str;
	this->per = per;
	this->vit = vit;

	hpMax = ((this->vit * 2) + (this->str / 2)) * 5;
	this->hp = hpMax;
	staminaMax = this->vit + (this->str / 2) + (this->per / 3) * 10;
	this->stamina = staminaMax;

	dmgMax = this->str * 2;
	dmgMin = this->str;

	this->floor = floor;

	money = 1.00;
}

void Character::gainExp(int exp)
{
	this->exp += exp; 
	if (this->exp >= expNext)
	{
		std::cout << "LEVEL UP AVAILABLE!!" << std::endl;
	}
}


void Character::lvlUp()
{
	while (exp >= expNext)
	{
		lvl++;
		exp -= expNext;
		expNext = static_cast <int>
			((50 / 3)*(pow(lvl, 3) -
				6 * pow(lvl, 2) +
				(17 * lvl) - 12) + 96);  //FIXME: exp gain to match difficulty
		statPoints++;
	}

	std::cout << "YOU ARE NOW LEVEL " << lvl << std::endl << std::endl;
	std::cout << "You have " << statPoints << " points to spend" << std::endl << std::endl;

	while (statPoints > 0)
	{
		std::cout << "1 Increase Strength" << std::endl;
		std::cout << "2 Increase Perception" << std::endl;
		std::cout << "3 Increase Vitality" << std::endl;
		std::cout << "4 Don't increase stats right now" << std::endl;
		int choice;
		std::cin >> choice;

		while (std::cin.fail())
		{
			std::cout << "faulty input" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cin >> choice;
		}

		std::cin.ignore(100, '\n');

		switch (choice)
		{
		case 1: //STRENGTH
			str++;
			statPoints--;
			std::cout << "STRENGTH INCREASED\n";
			break;
		case 2: //PERCEPTION
			per++;
			statPoints--;
			std::cout << "PERCEPTION INCREASED\n";
			break;
		case 3: //VITALITY
			vit++;
			statPoints--;
			std::cout << "VITALITY INCREASED\n";
			break;
		default:
			break;
		}

		if (choice = 4)
		{
			break;
		}
	}

}

void Character::updateStats()
{
	hpMax = ((this->vit * 2) + (this->str / 2)) * 5;
	this->hp = hpMax;
	staminaMax = this->vit + (this->str / 2) + (this->per / 3) * 10;
	this->stamina = staminaMax;

	dmgMax = this->str * 2;
	dmgMin = this->str;
}

void Character::rest()
{
	hp = hpMax;
	stamina = staminaMax;
}



std::string Character::printStats() const
{
	std::ostringstream out;

	out << "Stats:" << std::endl;
	out << "Name: " << name << std::endl;
	out << "Level: " << lvl << std::endl;
	out << "Exp: " << exp << " / " << expNext << std::endl;
	out << std::setw(15) << std::setfill('*') << " " << std::endl;
	out << "HP: " << hp << " / " << hpMax << "    ";
	out << "Stamina: " << stamina << " / " << staminaMax << std::endl;
	out << "Strength: " << str << std::endl;
	out << "Perception: " << per << std::endl;
	out << "Vitality: " << vit << std::endl;
	out << std::endl;
	out << "You have " << statPoints << " points to spend" << std::endl;
	out << std::endl;
	out << "Items:" << std::endl;
	out << "Weapon: " << weapon.getName() << " Lvl " << weapon.getLvl()
		<< "    " << weapon.getDmgMin() << " - " << weapon.getDmgMax() << " Damage\n";
	out << std::setw(8) << std::setfill(' ') << "Head: " << armor_Head.getName() << " Lvl "
		<< armor_Head.getLvl() << "    " << armor_Head.getDef() << " Armor\n";
	out << std::setw(8) << "Body: " << armor_Body.getName() << " Lvl "
		<< armor_Body.getLvl() << "    " << armor_Body.getDef() << " Armor\n";
	out << std::setw(8) << "Feet: " << armor_Feet.getName() << " Lvl "
		<< armor_Feet.getLvl() << "    " << armor_Feet.getDef() << " Armor\n";
	return out.str();
}

std::string Character::toString() const
{
	std::ostringstream out;
	out << name << " "<< lvl << " " << exp << " " << hp
		<< " " << stamina << " " << " " << " " << str 
		<< " " << per << " " << vit << " " << statPoints
		<< " " << floor;

	return out.str();
}

std::string Character::invToString()
{
	std::string inv;

	for (size_t i = 0; i < inventory.size(); i++)
	{
		inv += inventory[i].toString() + "\n";
	}
	return inv;
}
