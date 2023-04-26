#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class InformationDisplay
{
public:
	InformationDisplay();
	~InformationDisplay() = default;
	void displayData(sf::RenderWindow& window, const int life, const int score, const int stone, const int level, const int time);
	void setDtata(sf::Text& text, int size, sf::Vector2f position, sf::Color color);
	void displayTime(sf::RenderWindow& window, const int time);

protected:
	sf::Text m_life;
	sf::Text m_score;
	sf::Text m_stone;
	sf::Text m_level;
};