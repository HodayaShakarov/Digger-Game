#include "GameManager.h"

//--------------------------------------------------------------------------------------------------------------
GameManager::GameManager() : m_digger()
{
}

//--------------------------------------------------------------------------------------------------------------
bool GameManager::run(sf::RenderWindow& window)
{
	bool isNeedToRestart, isSucsses;
	int numOfLevel = 1; //משתנה שמציין את מספר השלב
	auto levelFile = std::string("Level1.txt");
	
	while (std::ifstream(levelFile))
	{
		isNeedToRestart = false, isSucsses = true;
		Level level(m_digger, levelFile);
		isSucsses = level.run(window, isNeedToRestart, m_digger, numOfLevel);
		if (isSucsses == false)
			return false;
		if (isNeedToRestart == false)
		{
			m_digger.setScore(SCORE_FOR_LEVEL);
			numOfLevel++;
		}
		levelFile = std::string("Level") + std::to_string(numOfLevel) + std::string(".txt");
	}
	return true;
}