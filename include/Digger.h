#pragma once
#include "DinamicObject.h"
#include "Const.h"

class Digger : public DinamicObject
{
public:
	Digger(); //c-tor
	void setDigger(const namesOfObjects index, sf::Vector2f location, int width, int height, int allowedStones, sf::Vector2f direction, int time);
	void handleEvent(sf::Keyboard::Key key);
	virtual void move(sf::Time deltaTime) override;
	sf::Vector2f getPosition() const;
	bool isAteAllDiamond();
	int getNumOfDiamond();
	void setNumOfDiamond(int num);
	int getScore() const;
	void setScore(int score);
	bool isAteAllowedStones();
	int getAllowedStones() const;
	void setAllowedStones();
	bool checkAllowedStones();
	void addStoneGift();
	void setLife();
	int getLife();
	int getTime() const;
	void setTime(int time);

protected:
	int m_life;
	int m_allowedStones;
	int m_score;
	int m_time;
	int m_numOfDiamond;

};