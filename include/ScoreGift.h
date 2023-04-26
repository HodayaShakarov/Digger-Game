#pragma once
#include "GiftType.h"

class Board;
class ScoreGift : public GiftType
{
public:
	ScoreGift(const namesOfObjects index, sf::Vector2f location, int width, int height);
	~ScoreGift() = default;
	virtual namesOfObjects collide(Digger& digger) override;
	virtual void collide(MonsterType& monster) override;

protected:

};