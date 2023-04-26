#include "Stone.h"
#include "Board.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
Stone::Stone(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	StaticObject(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבודקת התנגשות בין שחקן לאבן
namesOfObjects Stone::collide(Digger& digger)
{
	digger.setAllowedStones();
	return stone;
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבודקת התנגשות בין מפלצת לאבן
void Stone::collide(MonsterType& monster)
{
}
