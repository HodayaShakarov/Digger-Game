#include "ExitGame.h"
#include <iostream>

//--------------------------------------------------------------------------------------------------------------
ExitGame::ExitGame(const namesOfObjects index, sf::Vector2f location) : ButtonType(index, location)
{
}
//--------------------------------------------------------------------------------------------------------------
bool ExitGame::handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	if (ButtonType::isContain(event, window))
	{
		std::cout << "HODAYA\n";
		//exit(EXIT_SUCCESS);
		exit(0);

		return true;
	}
	return false;
}
