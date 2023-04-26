#include "Digger.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
Digger::Digger(): m_life(TOTAL_LIFE), m_score(0)
{
}

//--------------------------------------------------------------------------------------------------------------
void Digger::setDigger(const namesOfObjects index, sf::Vector2f location, int width, int height, int allowedStones, sf::Vector2f direction, int time)
{
	m_sprite.setTexture(Resources::getInstance().m_images[index]);
	setObjet(location, width, height);
	m_direction = direction;
	m_startPosition = location;
	m_allowedStones = allowedStones;
	m_time = time;
	m_numOfDiamond = 0;
}
//--------------------------------------------------------------------------------------------------------------
void Digger::handleEvent(sf::Keyboard::Key key)
{
	switch (key) 
	{
	case sf::Keyboard::Key::Space:
		if (m_direction.x != 0)
			setNextDirectionByRows();
		else if (m_direction.y != 0)
			setNextDirectionByColumns();
		m_nextDirection = { 0, 0 };
		break;
	case sf::Keyboard::Key::Left:
		m_nextDirection = checkDirection(Directions(key - 71));
		calculateSpeed(m_nextDirection, DIGGER_SPEED);
		break;
	case sf::Keyboard::Key::Right:
		m_nextDirection = checkDirection(Directions(key - 71));
		calculateSpeed(m_nextDirection, DIGGER_SPEED);
		break;
	case sf::Keyboard::Key::Up:
		m_nextDirection = checkDirection(Directions(key - 71));
		calculateSpeed(m_nextDirection, DIGGER_SPEED);
		break;
	case sf::Keyboard::Key::Down:
		m_nextDirection = checkDirection(Directions(key - 71));
		calculateSpeed(m_nextDirection, DIGGER_SPEED);
		break;
	}
}
//--------------------------------------------------------------------------------------------------------------
void Digger::move(sf::Time deltaTime)
{
	isCloseEnoughToAxis(deltaTime);
	if (isOutOfLimits((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
		m_sprite.move(m_direction * deltaTime.asSeconds());
}
//--------------------------------------------------------------------------------------------------------------
sf::Vector2f Digger::getPosition() const
{
	return m_sprite.getPosition();
}
//--------------------------------------------------------------------------------------------------------------
bool Digger::isAteAllDiamond()
{
	return m_numOfDiamond == 0;
}
//--------------------------------------------------------------------------------------------------------------
int Digger::getNumOfDiamond()
{
	return m_numOfDiamond;
}
//--------------------------------------------------------------------------------------------------------------
void Digger::setNumOfDiamond(int num)
{
	m_numOfDiamond += num;
}
//--------------------------------------------------------------------------------------------------------------
int Digger::getScore() const
{
	return m_score;
}
//--------------------------------------------------------------------------------------------------------------
void Digger::setScore(int score)
{
	m_score += score;
}
//--------------------------------------------------------------------------------------------------------------
bool Digger::isAteAllowedStones()
{
	return m_allowedStones == 0;
}
//--------------------------------------------------------------------------------------------------------------
int Digger::getAllowedStones() const
{
	return m_allowedStones;
}
//--------------------------------------------------------------------------------------------------------------
void Digger::setAllowedStones()
{
		m_allowedStones--;
	
}
//--------------------------------------------------------------------------------------------------------------
bool Digger::checkAllowedStones()
{
	return (m_allowedStones != 0);
}
//--------------------------------------------------------------------------------------------------------------
void Digger::addStoneGift()
{
	m_allowedStones += 2;
}
//--------------------------------------------------------------------------------------------------------------
void Digger::setLife()
{
	m_life--;
}
//--------------------------------------------------------------------------------------------------------------
int Digger::getLife()
{
	return m_life;
}
//--------------------------------------------------------------------------------------------------------------
int Digger::getTime() const
{
	return m_time;
}
//--------------------------------------------------------------------------------------------------------------
void Digger::setTime(int time)
{
	m_time += time;
}
