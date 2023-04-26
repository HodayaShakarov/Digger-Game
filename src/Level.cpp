#include "Level.h"

//--------------------------------------------------------------------------------------------------------------
Level::Level(Digger& digger, const std::string fileName) : m_board(digger, m_monsters, fileName), m_clock(), m_informationDisplay()
{
	Resources::getInstance().m_backgroundMusic.play();
}
Level::~Level()
{
	Resources::getInstance().m_backgroundMusic.stop();
}
//--------------------------------------------------------------------------------------------------------------
bool Level::run(sf::RenderWindow& window, bool& isNeedToRestart, Digger& digger,const int& numOfLevel)
{
	while (!digger.isAteAllDiamond()) //כל עוד השחקן לא אכל את כל האבנים בלוח
	{
		window.clear();
		m_board.draw(window);
		m_informationDisplay.displayData(window, digger.getLife(), digger.getScore(), digger.getAllowedStones(), numOfLevel,
										 digger.getTime() - m_timePassed.getElapsedTime().asSeconds());
		draw(window, digger);
		window.display();
		CheckLevelEvents(window, digger);
		digger.setLastPosition(); //שומר את המיקום האחרון שהיה
		move(digger);
		mainCollision(digger);

		if ((digger.isAteAllowedStones()) || digger.getTime() - m_timePassed.getElapsedTime().asSeconds() <= 0)
		{
			digger.setLife();
			isNeedToRestart = true;
			return true;
		}

		if (digger.getLife() == 0)
			return false;
	}
	return true;
}
//--------------------------------------------------------------------------------------------------------------
void Level::draw(sf::RenderWindow& window, Digger& digger)
{
	for (const auto& monster : m_monsters)
		monster->draw(window);
	digger.draw(window);
}
//--------------------------------------------------------------------------------------------------------------
void Level::CheckLevelEvents(sf::RenderWindow& window, Digger& digger)
{
	auto event = sf::Event{};
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
			break;
		case sf::Event::KeyPressed:
		{
			digger.handleEvent(event.key.code);
			digger.move(getDeltaTime());
			break;
		}
		default:
			break;
		}
	}
}
//--------------------------------------------------------------------------------------------------------------
void Level::move(Digger& digger)
{
	digger.move(m_clock.getElapsedTime());

	srand(time(0));
	auto deltaTime = getDeltaTime();
	for (const auto& monster : m_monsters)
	{
		monster.get()->setLastPosition();
		monster->move(deltaTime);
	}
}
//--------------------------------------------------------------------------------------------------------------
sf::Time Level::getDeltaTime()
{
	auto deltaTime = m_clock.restart();
	return deltaTime;
}
//--------------------------------------------------------------------------------------------------------------
void Level::mainCollision(Digger& digger)
{
	diggerCollideWithStaticObject(digger);
	diggerCollideWithMonster(digger);
	monsterCollideWithStaticObject(digger);
}
//--------------------------------------------------------------------------------------------------------------
void Level::diggerCollideWithMonster(Digger& digger)
{
	for (const auto& monster : m_monsters)
	{
		if (digger.getGlobalBoundsOfSprite().intersects(monster.get()->getGlobalBoundsOfSprite()))
		{
			monster.get()->collide(digger);
		}
	}
}
//--------------------------------------------------------------------------------------------------------------
void Level::diggerCollideWithStaticObject(Digger& digger)
{

	auto cell = sf::Vector2i(-1, -1);
	cell = digger.checkCollisionByDirection();
	if (cell != sf::Vector2i(-1, -1))
	{
		if (!m_board.checkIfEmpty(cell)) //אם התא לא ריק
		{
			if (digger.getGlobalBoundsOfSprite().intersects(m_board.getCell(cell)->getGlobalBoundsOfSprite()))
			{
				if (m_board.getCell(cell)->collide(digger) != wall) //אם התמונה שבתא לא קיר
					m_board.deleteObjectFromCell(cell); //נמחוק מהלוח
			}
		}
	}
}
//--------------------------------------------------------------------------------------------------------------
void Level::monsterCollideWithStaticObject(Digger& digger)
{
	auto cell = sf::Vector2i(-1, -1);
	for (const auto& monster : m_monsters)
	{
		cell = monster.get()->checkCollisionByDirection();
		if (cell != sf::Vector2i(-1, -1))
		{
			if (!m_board.checkIfEmpty(cell)) //אם התא לא ריק
			{
				if (monster.get()->getGlobalBoundsOfSprite().intersects(m_board.getCell(cell)->getGlobalBoundsOfSprite()))
					m_board.getCell(cell)->collide(*monster);
			}
		}
	}
}
bool Level::isOutOfTime(Digger& digger)
{
	if(digger.getTime() == OUT_OF_LIMIT_TIME)
		return false;
	return true;
}
//--------------------------------------------------------------------------------------------------------------
bool Level::checkIfEof()
{
	return m_board.checkIfEof();
}
