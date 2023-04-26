#include "ButtonType.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
ButtonType::ButtonType(const namesOfObjects index, sf::Vector2f location) : m_sprite(Resources::getInstance().m_images[index])
{
	m_sprite.setPosition(location);
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שמציגה את התפריט על המסך
void ButtonType::drawOnWindow(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבודקת אם הלחיצה נעשתה על הכפתור
bool ButtonType::isContain(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	if (m_sprite.getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
		return true;
	return false;
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שמחזירה את התמונה
sf::Sprite ButtonType::getSprite()
{
	return m_sprite;
}
