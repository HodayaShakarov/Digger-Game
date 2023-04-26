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
	auto image = sf::Texture(); // texture ����� ����� ����

	image.loadFromFile("Diamond.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("Digger.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("ExitGame.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("GameBackground.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("GameOver.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("Gift.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("MenuScreen.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("NewGame.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("RegularMonster.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("SpecialMonster.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("Stone.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("Wall.png");
	m_images.push_back(image); //����� ������ �������

	image.loadFromFile("Winner.png");
	m_images.push_back(image); //����� ������ �������

	m_font.loadFromFile("c:/Windows/Fonts/Arial.ttf");

	m_backgroundMusic.openFromFile("BackgroundMusic.wav");
	m_gameOverMusic.openFromFile("WinnerMusic.wav");
	m_winnerMusic.openFromFile("GameOverMusic.wav");
}
