#ifndef EVENT_H
#define EVENT_H
#include "Character.h"
#include <string>
#include <stdlib.h>
#include<cmath>


class Event
{
private:
	int numEvents;
	int liveEnemies;
	std::vector <Enemy> evEnemies;
	//bool enemyTurn;
public:
	Event();
	virtual ~Event();

	int generateEvent(Character& character);
	void generateEncounter(Character& character, const std::vector<Enemy>& enemies);
	void enemyEncounter(Character& character);
	void playerTurn(Character& character, int index);
	void enemyTurn(Character& character);
	void playerLose();
};

#endif // !EVENT_H
