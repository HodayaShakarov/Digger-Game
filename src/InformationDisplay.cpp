#include "InformationDisplay.h"
#include <iostream>

//--------------------------------------------------------------------------------------------------------------
InformationDisplay::InformationDisplay()
{
	m_life = sf::Text("Life: ", Resources::getInstance().m_font);
	m_score = sf::Text("Score: ", Resources::getInstance().m_font);
	m_stone = sf::Text("Stone: ", Resources::getInstance().m_font);
	m_level = sf::Text("Level: ", Resources::getInstance().m_font);

	auto color = sf::Color::Black;

	setDtata(m_life, 30, { 1070 ,250 }, color);

	setDtata(m_score, 30, { 1070, 350 }, color);

	setDtata(m_stone, 30, { 1070, 450 }, color);

	setDtata(m_level, 30, { 1070, 550 }, color);
}
//--------------------------------------------------------------------------------------------------------------
void InformationDisplay::displayData(sf::RenderWindow& window, const int life, const int score, const int stone, const int level, const int time)
{
	auto color = sf::Color::Black;

	window.draw(m_life); //הדפסה של הטקסט
	auto text = sf::Text(std::to_string(life), Resources::getInstance().m_font); //ממירה ממספר לטקסט ומציגה את הערך
	setDtata(text, 30, { 1085,290 }, color);
	window.draw(text);


	window.draw(m_score); //הדפסה של הטקסט
	auto text1 = sf::Text(std::to_string(score), Resources::getInstance().m_font); //ממירה ממספר לטקסט ומציגה את הערך
	setDtata(text1, 30, { 1085,390 }, color);
	window.draw(text1);

	window.draw(m_stone); //הדפסה של הטקסט
	auto text2 = sf::Text(std::to_string(stone), Resources::getInstance().m_font); //ממירה ממספר לטקסט ומציגה את הערך
	setDtata(text2, 30, { 1085,490 }, color);
	window.draw(text2);

	window.draw(m_level); //הדפסה של הטקסט
	auto text3 = sf::Text(std::to_string(level), Resources::getInstance().m_font); //ממירה ממספר לטקסט ומציגה את הערך
	setDtata(text3, 30, { 1085,590 }, color);
	window.draw(text3);

	displayTime(window, time);
}
//--------------------------------------------------------------------------------------------------------------
void InformationDisplay::setDtata(sf::Text& text, int size, sf::Vector2f position, sf::Color color)
{
	text.setCharacterSize(size); //משנה גודל
	text.setPosition(position); //משנה מקום
	text.setColor(color); //משנה צבע
}
//--------------------------------------------------------------------------------------------------------------
void InformationDisplay::displayTime(sf::RenderWindow& window, const int time)
{
	auto text = sf::Text();
	auto color = sf::Color();
	if (time / 60 >= 10 && time % 60 >= 10)
		text = sf::Text(std::to_string(time / 60) + ":" + std::to_string(time % 60), Resources::getInstance().m_font);
	else if (time / 60 < 10 && time % 60 >= 10)
		text = sf::Text(std::to_string(0) + std::to_string(time / 60) + ":" + std::to_string(time % 60), Resources::getInstance().m_font);
	else if (time / 60 >= 10 && time % 60 < 10)
		text = sf::Text(std::to_string(time / 60) + ":" + std::to_string(0) + std::to_string(time % 60), Resources::getInstance().m_font);
	else
		text = sf::Text(std::to_string(0) + std::to_string(time / 60) + ":" + std::to_string(0) + std::to_string(time % 60), Resources::getInstance().m_font);
	if (time % 60 <= 10 && time / 60 < 1)
		color = sf::Color::Red;
	else
		color = sf::Color::Black;
	setDtata(text, 60, { 1040, 100 }, color);
	window.draw(text);
}
