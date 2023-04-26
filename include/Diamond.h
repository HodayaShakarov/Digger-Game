#pragma once
#include "StaticObject.h"

class Board;
class Diamond : public StaticObject
{
public:
	Diamond(const namesOfObjects index, sf::Vector2f location, int width, int height);  //c-tor
	virtual namesOfObjects collide(Digger& digger) override; //פונקציה שבודקת התנגשות בין שחקן ליהלום
	virtual void collide(MonsterType& monster) override; //פונקציה שבודקת התנגשות בין מפלצת ליהלום

protected:

};