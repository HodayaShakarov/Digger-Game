#include "Diamond.h"
#include "Board.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
Diamond::Diamond(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	StaticObject(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
//������� ������ ������� ��� ���� ������
namesOfObjects Diamond::collide(Digger& digger)
{

	//if (digger.getNumOfDiamond() != 1) //�� �� ��� ������� ����
	{
		digger.setNumOfDiamond(-1); //����� ����� ��������
		digger.setScore(15); //����� ������
	}
	return diamond;
}
//--------------------------------------------------------------------------------------------------------------
//������� ������ ������� ��� ����� ������
void Diamond::collide(MonsterType& monster)
{
}
