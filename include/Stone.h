#pragma once
#include "StaticObject.h"

class Board;
class Stone : public StaticObject
{
public:
	Stone(const namesOfObjects index, sf::Vector2f location, int width, int height); //c-tor
	virtual namesOfObjects collide(Digger& digger) override; //פונקציה שבודקת התנגשות בין שחקן לאבן
	virtual void collide(MonsterType& monster) override; //פונקציה שבודקת התנגשות בין מפלצת לאבן

protected:

};