#pragma once
#include "ButtonType.h"

class NewGame : public ButtonType
{
public:
	NewGame(const namesOfObjects index, sf::Vector2f location);
	~NewGame() = default;
	virtual bool handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window) override;

protected:

};