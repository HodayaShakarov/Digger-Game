#include "StoneGift.h"
#include "Board.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
StoneGift::StoneGift(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	GiftType(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבודקת התנגשות בין שחקן למתנה
namesOfObjects StoneGift::collide(Digger& digger)
{
	digger.addStoneGift();
	return gift;
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבודקת התנגשות בין מפלצת למתנה
void StoneGift::collide(MonsterType& monster)
{
}
