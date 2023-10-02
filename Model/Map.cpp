#include <Map.h>

Map::Map(const unsigned int size) : _size(size) {}

Map::~Map(void) {}

void Map::load(void)
{
	this->_map = new int[this->_size * this->_size];
	for (int j = 0; j < this->_size; ++j)
	{
		for (int i = 0; i < this->_size; ++i)
			this->_map[COORD(i, j)] = 0;
	}
}

void Map::destroy(void)
{
	delete [] this->_map;
}

const char *Map::OutOfRangeException::what() const throw()
{
	return "map index out of range";
}

const unsigned int Map::getSize(void) const {return this->_size;}

const int *Map::getMap(void) const {return this->_map;}

const int Map::getMapCoord(int x, int y) const {return this->_map[COORD(x, y)];}

void Map::setMap(int x, int y, int value)
{
	if (x < 0 || x >= this->_size || y < 0 || y >= this->_size)
		throw OutOfRangeException();
	this->_map[COORD(x, y)] = value;
}