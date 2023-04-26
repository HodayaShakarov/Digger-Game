#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ButtonType.h"
#include "Resources.h"
#include "ExitGame.h"
#include "NewGame.h"
#include "Const.h"
using std::vector;

class Menu
{
public:
	Menu(sf::RenderWindow& window);
	~Menu() = default;
	bool CheckMenuEvents();
	void drawMenuWindow(sf::RenderWindow& window);
	bool handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window);

protected:
	sf::RenderWindow& m_window;
	sf::Sprite m_sprite;
	vector  <std::unique_ptr<ButtonType>> m_menu;
};