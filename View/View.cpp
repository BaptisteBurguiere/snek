#include <View.h>

View::View(void) : _size(10) {}

View::View(const unsigned int size) : _size(size) {}

View::~View(void) {}

void View::drawMap(void)
{
	std::cout << RESET << "╔";
	for (int i = 0; i < this->_size * 2; ++i)
		std::cout << "═";
	std::cout << "╗" << std::endl;
	for (int i = 0; i < this->_size; ++i)
	{
		std::cout << "║";
		for (int i = 0; i < this->_size * 2; ++i)
			std::cout << " ";
		std::cout << "║";
		std::cout << std::endl;
	}
	std::cout << "╚";
	for (int i = 0; i < this->_size * 2; ++i)
		std::cout << "═";
	std::cout << "╝" << std::endl;
}

void View::drawMapContent(const int *map)
{
	for (int j = 0; j < this->_size; ++j)
	{
		for (int i = 0; i < this->_size; ++i)
		{
			switch (map[COORD(i, j)])
			{
				case EMPTY:
					std::cout << RESET << "  ";
					break;

				case HEAD: case BODY:
					std::cout << BACKGROUND_GREEN << "  ";
					break;

				case APPLE:
					std::cout << BACKGROUND_RED << "  ";
					break;

				default:
					break;
			}
		}
		std::cout << CURSOR_NEXT_LINE;
	}
	std::cout << RESET;
}

void View::update(const int *map)
{
	std::system("clear");
	this->drawMap();
	std::cout << CURSOR_START;
	this->drawMapContent(map);
	std::cout << std::endl;
}

void View::displayScore(int score)
{
	std::system("clear");
	std::cout << "Your score: " << score << std::endl;
}