#pragma once
//מחלקת קבועים

const auto DIGGER = '/';
const auto MONSTER = '!';
const auto DIAMOND = 'D';
const auto WALL = '#';
const auto STONE = '@';
const auto SPACE = ' ';
const auto GIFT = '+';
const auto WIDTH_OF_BOARD = 1000;
const auto HIGHT_OF_WINDOW = 800;
const auto WIDTH_OF_WINDOW = 1200;
const auto TOTAL_LIFE = 3;
const auto SCORE_FOR_LEVEL = 20;
const auto DIGGER_SPEED = 100;
const auto MONSTER_SPEED = 80;
const auto EPSILON = 1;
const auto NUMBER_OF_DIRECTIONS = 4;
const auto OUT_OF_LIMIT_TIME = -1;


enum namesOfObjects
{
	diamond,
	digger,
	exitGame,
	gameBackground,
	GameOver,
	gift,
	menuScreen,
	newGame,
	regularMonster,
	specialMonster,
	stone,
	wall,
	winner
	//scoreGift,
	//stoneGift,
	//timeGift
};


enum Directions
{
	left,
	right,
	up,
	down,
	Default
};

