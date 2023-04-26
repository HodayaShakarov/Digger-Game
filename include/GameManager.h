#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Digger.h"

class GameManager
{
public:
	GameManager();
	bool run(sf::RenderWindow& window);

private:
	Digger m_digger;
};
