#include "Diamond.h"
#include "Board.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
Diamond::Diamond(const namesOfObjects index, sf::Vector2f location, int width, int height) :
	StaticObject(index, location, width, height)
{
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבודקת התנגשות בין שחקן ליהלום
namesOfObjects Diamond::collide(Digger& digger)
{

	//if (digger.getNumOfDiamond() != 1) //אם יש עוד יהלומים בלוח
	{
		digger.setNumOfDiamond(-1); //נוריד ממספר היהלומים
		digger.setScore(15); //נוסיף נקודות
	}
	return diamond;
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבודקת התנגשות בין מפלצת ליהלום
void Diamond::collide(MonsterType& monster)
{
}
