#pragma once
#include "GiftType.h"

class Board;
class TimeGift : public GiftType
{
public:
	TimeGift(const namesOfObjects index, sf::Vector2f location, int width, int height); //c-tor
	virtual namesOfObjects collide(Digger& digger) override; //פונקציה שבודקת התנגשות בין שחקן למתנה
	virtual void collide(MonsterType& monster) override; //פונקציה שבודקת התנגשות בין מפלצת למתנה

protected:

};