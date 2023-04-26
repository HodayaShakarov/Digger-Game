#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Menu.h"
#include "Const.h"
#include "GameManager.h"

class Controller
{
public:
	Controller(); //c-tor
	void run(); //פונקציה שמנהלת את המשחק

protected:
	void gameResult(bool& isSucsses); //פונקציה שבהתאם לתוצאת המשחק(ניצחון או הפסד) מציגה את התמונה והסאונד המתאימים
	sf::RenderWindow m_window; //חלון המשחק
	Menu m_menu; //תפריט
};