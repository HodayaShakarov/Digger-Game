#include "Menu.h"
#include <iostream>

//--------------------------------------------------------------------------------------------------------------
Menu::Menu(sf::RenderWindow& window) : m_window(window), m_sprite(Resources::getInstance().m_images[menuScreen])
{
	m_menu.push_back(std::make_unique<NewGame>(newGame, sf::Vector2f(40, 450)));
	m_menu.push_back(std::make_unique<ExitGame>(exitGame, sf::Vector2f(40, 550)));
	

}
//--------------------------------------------------------------------------------------------------------------
bool Menu::CheckMenuEvents()
{
	while (m_window.isOpen()) //כל עוד החלון פתוח נכנס ללולאה
	{
		m_window.clear();
		drawMenuWindow(m_window);
		m_window.display();
		if (auto event = sf::Event{}; m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				exit(0);
				break;

			case sf::Event::MouseButtonReleased:
			{
				if (handleClick(event.mouseButton, m_window))
				{
					std::cout << "jjj\n";
					return true;
					break;
				}
			}
			default:
				break;
			}
		}
	}
	return false;
}
//--------------------------------------------------------------------------------------------------------------
void Menu::drawMenuWindow(sf::RenderWindow& window)
{
	window.draw(m_sprite); //ציור הרקע
	for (const auto& button : m_menu) //ציור הכפתורים על התמונה
		button->drawOnWindow(window);
}
//--------------------------------------------------------------------------------------------------------------
bool Menu::handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	for (const auto& button : m_menu)
	{
		
		/*if(	button.get()->handleClick(event, window))
				return true;
			return false;*/
		(button.get()->handleClick(event, window));
		return true;
	}
}


