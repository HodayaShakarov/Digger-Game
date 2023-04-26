#include "RegularMonster.h"

//--------------------------------------------------------------------------------------------------------------
RegularMonster::RegularMonster(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	MonsterType(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
void RegularMonster::move(sf::Time deltaTime)
{
	int randomDirection = rand() % 4;
	m_nextDirection = checkDirection(Directions(randomDirection));
	calculateSpeed(m_nextDirection, MONSTER_SPEED);

	isCloseEnoughToAxis(deltaTime);
	if (isOutOfLimits((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
		m_sprite.move(m_direction * deltaTime.asSeconds());
}

