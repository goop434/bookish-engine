#include "Event.h"



Event::Event()
{
	numEvents = 1;
}


Event::~Event()
{
}

int Event::generateEvent(Character& character)
{
	//FiXME: change to rand or something later on
	int i = 0;

	return i;
}

void Event::generateEncounter(Character& character, const std::vector<Enemy>& enemies)
{
	int floor = character.getFloor();
	int points = pow(2, floor) + 5;
	std::vector<Enemy> possibleFoes;


	//make a vector of possible encounters for this floor
	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (enemies[i].getDRating() <= points)
		{
			possibleFoes.push_back(enemies[i]);
		}
	}

	//"spend" points on enemies for encounter
	int i = possibleFoes.size() - 1;
	while (points > 0 && i >= 0)
	{
		
		int num = rand() % possibleFoes.size();
		if (num == 0 && possibleFoes[i].getDRating() <= points)
		{
			evEnemies.push_back(possibleFoes[i]);
			points -= possibleFoes[i].getDRating();
		}
		i--;

		if (i == 0 && evEnemies.size() == 0)
		{
			i = possibleFoes.size() - 1;
		}
	}

}

void Event::enemyTurn(Character& character)
{
	for (size_t i = 0; i < evEnemies.size(); i++)
	{
		int attackRoll = rand() % 100 + 1;
		if (attackRoll <= evEnemies[i].getAccuracy())
		{
			int dmg = evEnemies[i].attack();
			character.takeDamage(dmg);
			std::cout << "\n" << evEnemies[i].getName() << " deals " << dmg << " damage\n";
		}
		else
		{
			std::cout << "\nYou dodge the" << evEnemies[i].getName() << "'s attack\n";
		}

	}

}

void Event::playerTurn(Character& character, int index = 0)
{
	int attackRoll = rand() % 100 + 1;

	if (attackRoll >= 10)
	{
		int damage = character.getDamage();
		if (!character.loseStamina(2))
		{
			damage /= 2;
			std::cout << "\nYou're too tired to fight effectively!\n";
		}
		evEnemies[index - 1].takeDamage(damage);

		std::cout << "\nYou hit " << evEnemies[index - 1].getName()
			<< " for " << damage << " damage\n";

		if (evEnemies[index - 1].getHp() <= 0)
		{
			int exp = evEnemies[index - 1].dropExp();
			std::cout << "\nEnemy Defeated! " << exp << " Exp\n";
			character.gainExp(exp);
			int itemRoll = rand() % 100 + 1;
			int rarity = -1;
			//FIXME: drop Items
			liveEnemies--;


			
		}
	}
	else
	{
		std::cout << "You miss\n";
	}

}

void Event::enemyEncounter(Character& character)
{
	//End conditions
	bool escape = false;     //FIXME: End battle
	bool playerLose = false;
	bool playerWin = false;

	//Battle Variables
	int liveEnemies = evEnemies.size();
	int coinToss = rand() % 2;


	std::cout << "\nEnemy Enconter!" << std::endl << std::endl;
	for (size_t i = 0; i < evEnemies.size(); i++)
	{
		std::cout << evEnemies[i].getName() << " "
			<< evEnemies[i].getHpMax() << " HP\n";
	}


	while (!escape && !playerLose && !playerWin)
	{
		
			std::cout << "\nWhat will you do?" << std::endl << std::endl;
			std::cout << "1 Attack" << std::endl;
			std::cout << "2 Defend" << std::endl;
			std::cout << "3 Item" << std::endl;
			std::cout << "4 Run" << std::endl;

			int choice;
			std::cin >> choice;
			//system("CLS");
			while (std::cin.fail())
			{
				std::cout << "faulty input" << std::endl;
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cin >> choice;
			}

			switch (choice)
			{
			case 1: //ATTACK

				
					std::cout << "Select Enemy:" << std::endl << std::endl;

					for (size_t i = 0; i < evEnemies.size(); i++)
					{
						if (evEnemies[i].isAlive())
						{
							std::cout << (i + 1) << ": " << evEnemies[i].getName()
								<< " " << evEnemies[i].getHp() << " / "
								<< evEnemies[i].getHpMax() << " HP\n";
						}
						else
						{
							std::cout << "defeated\n";
						}
					}
					std::cout << (evEnemies.size() + 1) << " Back\n";
					int index;
					std::cin >> index;
					while (std::cin.fail() || index <= 0 || index > evEnemies.size() + 1)
					{
						std::cout << "faulty input" << std::endl;
						std::cin.clear();
						std::cin.ignore(100, '\n');
						std::cin >> index;
					}

					if (index == evEnemies.size() + 1)
					{
						break;
					}

					if (coinToss == 0)
					{
						enemyTurn(character);
						if (!character.isAlive())
						{
							playerLose = true;
						}
						else
						{
							playerTurn(character, index);
							if (liveEnemies <= 0)
							{
								playerWin = true;
								break;
							}
						}
					}
					else
					{
						playerTurn(character, index);
						if (liveEnemies <= 0)
						{
							playerWin = true;
							break;
						}
						else
						{
							enemyTurn(character);
							if (!character.isAlive())
							{
								playerLose = true;
							}
						}
					}
			
				break;
			case 2: //DEFEND
				break;
			case 3: //ITEM
				break;
			case 4: //RUN
				if (character.getStamina() >= evEnemies[0].getPursuit() * evEnemies.size())
				{
					character.loseStamina(10);
					std::cout << "\nGot Away!\n";
					escape = true;
				}
				else
				{
					character.loseStamina(10);
					std::cout << "\nCouldn't Escape!\n";
				}
				break;
			default:
				break;
			}
	}
		
		if (playerLose)
		{
			std::cout << "\nYou Are Defeated!\n";
		}

	

}
