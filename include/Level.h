#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"
#include "MonsterType.h"
#include "Digger.h"
#include "Resources.h"
#include "InformationDisplay.h"
using std::vector;

class Level
{
public:
	Level(Digger& digger, const std::string fileName);
	~Level()/* = default*/;
	bool run(sf::RenderWindow& window, bool& isNeedToRestart, Digger& digger,const int& numOfLevel);
	void draw(sf::RenderWindow& window, Digger& digger);
	void CheckLevelEvents(sf::RenderWindow& window, Digger& digger);
	void move(Digger& digger);
	sf::Time getDeltaTime();
	void mainCollision(Digger& digger);
	void diggerCollideWithMonster(Digger& digger);
	void diggerCollideWithStaticObject(Digger& digger);
	void monsterCollideWithStaticObject(Digger& digger);
	bool isOutOfTime(Digger& digger);
	bool checkIfEof();

protected:
	vector <std::unique_ptr<MonsterType>> m_monsters;
	Board m_board;

	sf::Clock m_clock;
	sf::Clock m_timePassed;
	InformationDisplay m_informationDisplay;
};

