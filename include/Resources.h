#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
using std::vector;

class Resources
{
public:
	~Resources() = default;
	static Resources& getInstance();

	vector <sf::Texture> m_images; //vector of images
	sf::Font m_font;
	sf::Music m_backgroundMusic;
	sf::Music m_winnerMusic;
	sf::Music m_gameOverMusic;

protected:
	Resources();
	Resources(const Resources& other) = default;
	void insertImageToVector();
};