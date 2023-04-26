#include "MonsterType.h"

//--------------------------------------------------------------------------------------------------------------
MonsterType::MonsterType(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	DinamicObject(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
void MonsterType::collide(Digger& digger)
{
	if (digger.getLife() != 0)
	{
		digger.setLife();
		digger.getStartPosition();
		this->getStartPosition();
	}
}