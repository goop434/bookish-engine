#ifndef GAME_H
#define GAME_H
#include "Event.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <sstream>

class Game
{
private:
	bool running;
	//Character related
	int activeCharacter;
	std::vector <Character> characters;
	std::string characterFile;

	//World related
	std::string enemyFile;
	std::string weaponFile;
	std::string armorFile;
	std::vector <Enemy> enemies;


public:
	Game();
	virtual ~Game();

	//Functions
	void startGame();
	void mainMenu();
	void createNewCharacter();
	void saveCharacters();
	void loadCharacters();
	void loadEnemies();
	void selectCharacters();
	void travel();

	//Acessors
	bool getRunning() { return running; }

};

#endif // !GAME_H
