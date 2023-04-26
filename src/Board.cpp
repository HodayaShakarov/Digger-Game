#include "Board.h"
#include "Level.h"

//--------------------------------------------------------------------------------------------------------------
//c-tor
Board::Board(Digger& digger, vector <std::unique_ptr<MonsterType>>& monstersVec, const std::string fileName) : m_file(std::ifstream(fileName))
{
	openBoardFile();
	readLevelFile(digger, monstersVec);
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שקוראת את השלב
void Board::readLevelFile(Digger& digger1, vector <std::unique_ptr<MonsterType>>& monstersVec)
{
	int row, col, allowedStones, limitTime;
	m_file >> row >> col >> allowedStones >> limitTime;
	std::cout << col;
	int width = WIDTH_OF_BOARD / col; //חישוב רוחב של תא
	int height = HIGHT_OF_WINDOW / row; //חישוב גובה של תא
	m_gameBoard.resize(row);
	char c = m_file.get();
	srand(time(0)); //אתחול

	for (int i = 0; i < row; i++) //לולאה שרצה על שורות מטריצת הלוח עד גודל המערך
	{
		for (int j = 0; j < col; j++) //לולאה שרצה על עמודות מטריצת הלוח עד גודל המערך
		{
			c = m_file.get();
			insertData(digger1, monstersVec, c, i, j, width, height, allowedStones, limitTime);
		}
		c = m_file.get();
	}
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שמעדכנת את נתוני האוביקטים
void Board::insertData(Digger& digger1, vector <std::unique_ptr<MonsterType>>& monstersVec, char c, int i, int j, int width, int height, int allowedStones, int limitTime)
{
	sf::Vector2f location(j * width, i * height); //חישוב נקודה שמאלית עליונה
	//sf::Vector2f location((j * width) + (width / 2), (i * height) + (height / 2)); //חישוב נקודת מרכז
	switch (c) //:c בדיקה האם 
	{
	case DIAMOND: //במקרה שהתו הוא יהלום
	{
		m_gameBoard[i].push_back(std::make_unique<Diamond>(diamond, location, width, height));
		digger1.setNumOfDiamond(1);
		break;
	}
	case STONE: //במקרה שהתו הוא אבן
	{
		m_gameBoard[i].push_back(std::make_unique<Stone>(stone, location, width, height));
		break;
	}
	case WALL: //במקרה שהתו הוא קיר
	{
		m_gameBoard[i].push_back(std::make_unique<Wall>(wall, location, width, height));
		break;
	}
	case GIFT: //במקרה שהתו הוא מתנה
	{	
		int giftType = rand() % 3;
		if(giftType == 0)
			m_gameBoard[i].push_back(std::make_unique<ScoreGift>(gift, location, width, height));
		if(giftType == 1)
			m_gameBoard[i].push_back(std::make_unique<StoneGift>(gift, location, width, height));
		if(giftType == 2)
			m_gameBoard[i].push_back(std::make_unique<TimeGift>(gift, location, width, height));
		break;
	}
	case DIGGER: //במקרה שהתו הוא שחקן
	{
		digger1.setDigger(digger, location, width, height, allowedStones, sf::Vector2f(0, 0), limitTime);
		m_gameBoard[i].push_back(nullptr);
		break;
	}
	case MONSTER: //במקרה שהתו הוא מפלצת
	{
		int monsterType = rand() % 2;
		if (monsterType == 0)
			monstersVec.push_back(std::make_unique<RegularMonster>(regularMonster, location, width, height));
		else if(monsterType == 1)
			monstersVec.push_back(std::make_unique<SpecialMonster>(specialMonster, location, width, height, digger1));
		m_gameBoard[i].push_back(nullptr);
		break;
	}
	case SPACE:
		m_gameBoard[i].push_back(nullptr);
		break;
	default:
		break;
	}
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שמציגה את הלוח על המסך
void Board::draw(sf::RenderWindow& window)
{
	window.clear(sf::Color(222, 184, 135)); //צביעת רקע החלון
	sf::Sprite sprite(Resources::getInstance().m_images[gameBackground]);
	window.draw(sprite);
	for (int i = 0; i < m_gameBoard.size(); i++)
	{
		for (int j = 0; j < m_gameBoard[i].size(); j++) 
		{
			if(m_gameBoard[i][j] != nullptr)
				m_gameBoard[i][j]->draw(window);
		}
	}
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שבודקת אם הגיע לסיום השלב
bool Board::checkIfEof()
{
	return !m_file.eof();
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שמקבלת מיקום של תא בלוח ומחזירה את תוכן התא
 StaticObject* Board::getCell(sf::Vector2i cell)
{
	 return m_gameBoard[cell.y][cell.x].get();
}
 //--------------------------------------------------------------------------------------------------------------
 //פונקציה שמוחקת תא מהלוח
void Board::deleteObjectFromCell(sf::Vector2i& cell)
{
	m_gameBoard[cell.y][cell.x] = nullptr;
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שמקבלת מיקום תא ומחזירה אם התא ריק
bool Board::checkIfEmpty(sf::Vector2i cell)
{
	if (m_gameBoard[cell.y][cell.x] == nullptr)
		return true;
	return false;
}
//--------------------------------------------------------------------------------------------------------------
//פונקציה שפותחת נכון את קובץ השלב
void Board::openBoardFile()
{
	if (!m_file.is_open())
	{
		std::cerr << "Can't open the file \n";
		exit(EXIT_FAILURE);
	}
}
