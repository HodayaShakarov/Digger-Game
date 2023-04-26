#pragma once
#include "GiftType.h"

class Board;
class StoneGift : public GiftType
{
public:
	StoneGift(const namesOfObjects index, sf::Vector2f location, int width, int height); //c-tor
	virtual namesOfObjects collide(Digger& digger) override; //������� ������ ������� ��� ���� �����
	virtual void collide(MonsterType& monster) override; //������� ������ ������� ��� ����� �����

protected:

};