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
	void readLevelFile(Digger& digger1, vector <std::unique_ptr<MonsterType>>& monstersVec); //������� ������ �� ����
	void insertData(Digger& digger1, vector <std::unique_ptr<MonsterType>>& monsterVec, char c, int i, int j, int width, int height, int allowedStones, int limitTime); //������� ������� �� ����� ���������
	void draw(sf::RenderWindow& window); //������� ������ �� ���� �� ����
	bool checkIfEof(); //������� ������ �� ���� ����� ����
	StaticObject* getCell(sf::Vector2i cell); //������� ������ ����� �� �� ���� ������� �� ���� ���
	void deleteObjectFromCell(sf::Vector2i& cell); //������� ������ �� �����
	bool checkIfEmpty(sf::Vector2i cell); //������� ������ ����� �� ������� �� ��� ���

protected:
	void openBoardFile(); //������� ������ ���� �� ���� ����

	ifstream m_file; //����� ����� �� �����
	vector<vector<std::unique_ptr<StaticObject>>> m_gameBoard; //������ ��������� ������� 
};
