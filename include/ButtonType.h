#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Const.h"

class ButtonType
{
public:
	ButtonType(const namesOfObjects index, sf::Vector2f location); //c-tor
	void drawOnWindow(sf::RenderWindow& window); //������� ������ �� ������ �� ����
	virtual bool handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window) = 0; //������� ������ ������ ������ �� ����� �����
	bool isContain(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window); //������� ������ �� ������ ����� �� ������
	sf::Sprite getSprite(); //������� ������� �� ������

protected:
	sf::Sprite m_sprite; //����� ����� �� �������
};