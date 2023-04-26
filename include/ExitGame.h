#pragma once
#include "ButtonType.h"

class ExitGame : public ButtonType
{
public:
	ExitGame(const namesOfObjects index, sf::Vector2f location);
	~ExitGame() = default;
	virtual bool handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window) override;

protected:

};