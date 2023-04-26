#pragma once
#include "MonsterType.h"
#include "Digger.h"

class SpecialMonster : public MonsterType
{
public:
	SpecialMonster(const namesOfObjects index, sf::Vector2f location, int width, int height, Digger& digger);
	~SpecialMonster() = default;
	virtual void move(sf::Time deltaTime) override;
	float manhattan…Distance(sf::Vector2f possibleDestigntion);

protected:
	Digger& m_digger;
};