#include "Resources.h"

//--------------------------------------------------------------------------------------------------------------
Resources& Resources::getInstance()
{
	static Resources m_instance;
	return m_instance;
}
//--------------------------------------------------------------------------------------------------------------
Resources::Resources()
{
	insertImageToVector();
}
//--------------------------------------------------------------------------------------------------------------
void Resources::insertImageToVector()
{
	auto image = sf::Texture(); // texture יצירת תמונה מסוג

	image.loadFromFile("Diamond.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("Digger.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("ExitGame.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("GameBackground.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("GameOver.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("Gift.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("MenuScreen.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("NewGame.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("RegularMonster.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("SpecialMonster.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("Stone.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("Wall.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	image.loadFromFile("Winner.png");
	m_images.push_back(image); //הכנסת התמונה לווקטור

	m_font.loadFromFile("c:/Windows/Fonts/Arial.ttf");

	m_backgroundMusic.openFromFile("BackgroundMusic.wav");
	m_gameOverMusic.openFromFile("WinnerMusic.wav");
	m_winnerMusic.openFromFile("GameOverMusic.wav");
}
