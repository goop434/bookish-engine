#include "Game.h"


Game::Game()
{
	running = true;
	activeCharacter = 0;
	characterFile = "characters.txt";
	enemyFile = "Enemy List.txt";
	weaponFile = "Weapon List.txt";
	armorFile = "Armor List.txt";
}

Game::~Game()
{
}

void Game::startGame()
{
	loadCharacters();
	loadEnemies();

}


void Game::mainMenu()
{

	std::cout << std::endl << "|MAIN MENU|" << std::endl << std::endl;

	std::cout << "1 Save & Quit" << std::endl;
	std::cout << "2 Explore" << std::endl;
	std::cout << "3 Shop" << std::endl;
	std::cout << "4 Level Up" << std::endl;
	std::cout << "5 Rest" << std::endl;
	std::cout << "6 Stats" << std::endl;
	std::cout << "7 New Game" << std::endl;
	std::cout << "8 Save Game" << std::endl;
	std::cout << "9 Load Game" << std::endl;
	std::cout << std::endl;

	char choice;
	std::cin >> choice;

	while (std::cin.fail())
	{
		std::cout << "faulty input" << std::endl;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cin >> choice;
	}

	std::cin.ignore(100, '\n');
	system("CLS");

	switch (choice)
	{
	case '1': //QUIT
		saveCharacters();
		running = false;
		break;
	case '2': //EXPLORE
		travel();
		break;
	case '4': //LEVEL UP
		characters[activeCharacter].lvlUp();
		characters[activeCharacter].updateStats();
		break;
	case '5': //REST
		characters[activeCharacter].rest();
		break;
	case '6': //STATS
		characters[activeCharacter].gainExp(20);
		std::cout << std::endl << characters[activeCharacter].printStats()<< std::endl;
		break;
	case '7':
		createNewCharacter();
		break;
	case '8':
		saveCharacters();
		break;
	case '9':
		selectCharacters();
		break;
	default:
		break;
	}
}

void Game::createNewCharacter()
{
	std::string name;
	std::cout << "Character name: ";
	getline(std::cin, name);
	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].Initialize(name);
}

void Game::saveCharacters()
{
	std::ofstream outFile(characterFile);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].toString() << "\n";
		}
	}

	outFile.close();
}

void Game::loadCharacters()
{
	std::ifstream inFile(characterFile);
	std::string data;
	std::string name;
	int lvl;
	int exp;
	int hp;
	int stamina;
	int str;
	int per;
	int vit;
	int statPoints;
	int floor;

	std::stringstream in;

	if (inFile.is_open())
	{
		while (getline(inFile, data))
		{
			in.str(data);

			//std::cin.ignore();   FIXME: ALLOW FOR NAMES W/ SPACES
			//getline(in, name, ',');
			in >> name;
			in >> lvl;
			in >> exp;
			in >> hp;
			in >> stamina;
			in >> str;
			in >> per;
			in >> vit;
			in >> statPoints;
			in >> floor;

			Character temp;
			temp.Initialize(name, lvl, exp, statPoints, hp, stamina,
				str, per, vit, floor);

			characters.push_back(temp);
			activeCharacter = (characters.size() - 1);
			//std::cout << characters[activeCharacter].toString();

			in.clear();
		}
	}

	inFile.close();
}

void Game::loadEnemies()
{
	std::ifstream inFile(enemyFile);
	std::string data;
	std::string name;
	std::string last;
	int hpMax;
	int dmgMin, dmgMax;
	int armor;
	int acc;
	int pursuit;
	int expReward;
	int dRating;
	std::pair <std::string, int> drop;
	std::vector <std::pair<std::string, int>> itemPool;

	std::stringstream in;

	if (inFile.is_open())
	{
		while (inFile >> dRating)
		{
			inFile.ignore();
			getline(inFile, name, ','); 
			inFile >> last;
			inFile >> hpMax;
			inFile >> last;
			inFile >> armor;
			inFile >> last;
			inFile >> dmgMin;
			inFile >> dmgMax;
			inFile >> last;
			inFile >> acc;
			inFile >> last;
			inFile >> pursuit;
			inFile >> last;
			inFile >> expReward;
			
			inFile >> last;
			inFile >> data;
			inFile.ignore();
			
			int dropChance;
			std::string itemName;
			while (data != "END")
			{

				getline(inFile, itemName, ',');
				drop.first = itemName;
				drop.second = std::stoi(data);
				itemPool.push_back(drop);
				inFile >> data;
				inFile.ignore();
			}
			

			Enemy enemyType;
			enemyType.initialize(name, hpMax, armor, dmgMin, dmgMax, acc, pursuit, 
				expReward, dRating, itemPool);

			enemies.push_back(enemyType);

			itemPool.clear();

		}
	}

	inFile.close();

	//for testing
	//for (size_t i = 0; i < enemies.size(); i++)
	//{
		//std::cout << enemies[i].toString() << std::endl;
		//enemies[i].printItemPool();
		
		//std::cout << enemies[i].getName() << " loaded!\n";
	//``}

}

void Game::selectCharacters()
{
	for (size_t i = 0; i < characters.size(); i++)
	{
		std::cout << (i + 1) << " " << characters[i].getName()
			<< ": Level " << characters[i].getLvl() << std::endl;
	}

	int choice;
	std::cin >> choice;
	while (std::cin.fail() || choice <= 0 || choice > characters.size())
	{
		std::cout << "Faulty Input" << std::endl;
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cin >> choice;
	}

	std::cin.ignore();

	activeCharacter = (choice - 1);

	std::cout << "\n Game Loaded\n";
}

void Game::travel()
{
	Event ev;

	int i = ev.generateEvent(characters[activeCharacter]);

	if (i == 0)
	{
		ev.generateEncounter(characters[activeCharacter], enemies);
	}

	//for testing
	//std::cout << characters[activeCharacter].getFloor() << std::endl;
	//for (size_t i = 0; i < enemies.size(); i++)
	//{
	//std::cout << enemies[i].getName() << "\n";
	//}

	switch (i)
	{
	case 0: 	//Enemy encounter

		ev.enemyEncounter(characters[activeCharacter]);
		break;
	case 1: 	//Other event
		break;
	default:
		break;
	}
}