#include "NewGame.h"
#include <iostream>

//--------------------------------------------------------------------------------------------------------------
NewGame::NewGame(const namesOfObjects index, sf::Vector2f location) : ButtonType(index, location)
{
}
//--------------------------------------------------------------------------------------------------------------
bool NewGame::handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	if (ButtonType::isContain(event, window))
		return true;
	return false;
}
