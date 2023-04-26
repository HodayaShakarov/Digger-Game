#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "StaticObject.h"
#include "Const.h"
#include "Resources.h"
#include "Diamond.h"
#include "Wall.h"
#include "Stone.h"
#include "ScoreGift.h"
#include "StoneGift.h"
#include "TimeGift.h"
#include "RegularMonster.h"
#include "SpecialMonster.h"
#include "Digger.h"
#include "DinamicObject.h"
using std::vector;
using std::ifstream;

class Level;
class Board
{
public:
	Board(Digger& digger, vector <std::unique_ptr<MonsterType>>& monstersVec, const std::string fileName); //c-tor
	void readLevelFile(Digger& digger1, vector <std::unique_ptr<MonsterType>>& monstersVec); //פונקציה שקוראת את השלב
	void insertData(Digger& digger1, vector <std::unique_ptr<MonsterType>>& monsterVec, char c, int i, int j, int width, int height, int allowedStones, int limitTime); //פונקציה שמעדכנת את נתוני האוביקטים
	void draw(sf::RenderWindow& window); //פונקציה שמציגה את הלוח על המסך
	bool checkIfEof(); //פונקציה שבודקת אם הגיע לסיום השלב
	StaticObject* getCell(sf::Vector2i cell); //פונקציה שמקבלת מיקום של תא בלוח ומחזירה את תוכן התא
	void deleteObjectFromCell(sf::Vector2i& cell); //פונקציה שמוחקת תא מהלוח
	bool checkIfEmpty(sf::Vector2i cell); //פונקציה שמקבלת מיקום תא ומחזירה אם התא ריק

protected:
	void openBoardFile(); //פונקציה שפותחת נכון את קובץ השלב

	ifstream m_file; //משתנה שקורא את הקובץ
	vector<vector<std::unique_ptr<StaticObject>>> m_gameBoard; //מטריצת האוביקטים הסטטיים 
};
