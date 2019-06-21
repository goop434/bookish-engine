#include <iostream>
#include <fstream>
#include <sstream>
#include "Game.h"
using namespace std;

int main()
{
	Game game;
	game.startGame();
	while (game.getRunning())
	{
		game.mainMenu();
	}
	return 0;
}