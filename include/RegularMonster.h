#pragma once
#include "MonsterType.h"
#include "Const.h"

class RegularMonster : public MonsterType
{
public:
	RegularMonster(const namesOfObjects index, sf::Vector2f location, int width, int height);
	~RegularMonster() = default;
	virtual void move(sf::Time deltaTime) override;

protected:

};