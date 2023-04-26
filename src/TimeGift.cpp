#include "TimeGift.h"
#include "Board.h"

//--------------------------------------------------------------------------------------------------------------
TimeGift::TimeGift(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	GiftType(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
namesOfObjects TimeGift::collide(Digger& digger)
{
	digger.setTime(20);
	return gift;
}
//--------------------------------------------------------------------------------------------------------------
void TimeGift::collide(MonsterType& monster)
{
}
