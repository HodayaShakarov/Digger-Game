#include "ScoreGift.h"
#include "Board.h"

//--------------------------------------------------------------------------------------------------------------
ScoreGift::ScoreGift(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	GiftType(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
namesOfObjects ScoreGift::collide(Digger& digger)
{
	digger.setScore(20);
	return gift;
}
//--------------------------------------------------------------------------------------------------------------
void ScoreGift::collide(MonsterType& monster)
{
}
