#pragma once
#include "StaticObject.h"

class Board;
class Stone : public StaticObject
{
public:
	Stone(const namesOfObjects index, sf::Vector2f location, int width, int height); //c-tor
	virtual namesOfObjects collide(Digger& digger) override; //������� ������ ������� ��� ���� ����
	virtual void collide(MonsterType& monster) override; //������� ������ ������� ��� ����� ����

protected:

};