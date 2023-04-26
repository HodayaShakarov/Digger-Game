#include "StoneGift.h"
#include "Board.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
StoneGift::StoneGift(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	GiftType(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
//������� ������ ������� ��� ���� �����
namesOfObjects StoneGift::collide(Digger& digger)
{
	digger.addStoneGift();
	return gift;
}
//--------------------------------------------------------------------------------------------------------------
//������� ������ ������� ��� ����� �����
void StoneGift::collide(MonsterType& monster)
{
}
