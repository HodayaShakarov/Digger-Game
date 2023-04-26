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
	void run(); //������� ������ �� �����

protected:
	void gameResult(bool& isSucsses); //������� ������ ������ �����(������ �� ����) ����� �� ������ ������� ��������
	sf::RenderWindow m_window; //���� �����
	Menu m_menu; //�����
};