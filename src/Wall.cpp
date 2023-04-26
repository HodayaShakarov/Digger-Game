#include "Wall.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
Wall::Wall(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	StaticObject(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבודקת התנגשות בין שחקן לקיר
namesOfObjects Wall::collide(Digger& digger)
{
	digger.setPosition();
	digger.setDirection({ 0,0 }); //עוצר את השחקן במקום
	return wall;
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבודקת התנגשות בין מפלצת לקיר
void Wall::collide(MonsterType& monster)
{
	monster.setPosition();
}
