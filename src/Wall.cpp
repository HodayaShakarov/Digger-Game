#include "Wall.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
Wall::Wall(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	StaticObject(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
//������� ������ ������� ��� ���� ����
namesOfObjects Wall::collide(Digger& digger)
{
	digger.setPosition();
	digger.setDirection({ 0,0 }); //���� �� ����� �����
	return wall;
}
//--------------------------------------------------------------------------------------------------------------
//������� ������ ������� ��� ����� ����
void Wall::collide(MonsterType& monster)
{
	monster.setPosition();
}
