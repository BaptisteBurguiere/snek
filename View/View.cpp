#include <View.h>

View::View(void) : _size(10) {}

View::View(const unsigned int size) : _size(size) {}

View::~View(void) {}

void View::drawMap(void)
{
	std::cout << RESET << "╔";
	for (int i = 0; i < this->_size; ++i)
		std::cout << "═";
	std::cout << "╗" << std::endl;
	for (int i = 0; i < this->_size; ++i)
	{
		std::cout << "║";
		for (int i = 0; i < this->_size; ++i)
			std::cout << " ";
		std::cout << "║";
		std::cout << std::endl;
	}
	std::cout << "╚";
	for (int i = 0; i < this->_size; ++i)
		std::cout << "═";
	std::cout << "╝" << std::endl;
}