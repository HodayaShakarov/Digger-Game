#include "Controller.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
Controller::Controller() : m_window(sf::VideoMode(WIDTH_OF_WINDOW, HIGHT_OF_WINDOW), "Digger Game"), m_menu(m_window)
{
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שמנהלת את המשחק
void Controller::run()
{
	bool isSucsses = true;
	while (m_menu.CheckMenuEvents())
	{
		GameManager gameManager;
		isSucsses = gameManager.run(m_window);
		gameResult(isSucsses);
	}
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבהתאם לתוצאת המשחק(ניצחון או הפסד) מציגה את התמונה והסאונד המתאימים
void Controller::gameResult(bool& isSucsses)
{
	auto sprite = sf::Sprite();
	if (!isSucsses)
	{
		m_window.clear();
		sprite.setTexture(Resources::getInstance().m_images[winner]);
		Resources::getInstance().m_winnerMusic.play();
	}
	else
	{
		m_window.clear();
		sprite.setTexture(Resources::getInstance().m_images[GameOver]);
		Resources::getInstance().m_gameOverMusic.play();
	}
	m_window.draw(sprite);
	m_window.display();

	if (auto event = sf::Event{}; m_window.pollEvent(event))
		if (event.type == sf::Event::Closed)
		{
			if (isSucsses)
				Resources::getInstance().m_gameOverMusic.stop();
			else
				Resources::getInstance().m_winnerMusic.stop();
			return;
		}
}

