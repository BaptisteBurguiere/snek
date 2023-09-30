#include <Coord.h>

Coord::Coord(void) 
{
	this->_coord[0] = 0;
	this->_coord[1] = 0;
}

Coord::Coord(int x, int y)
{
	this->_coord[0] = x;
	this->_coord[1] = y;
}

Coord::~Coord(void) {}

Coord &Coord::operator=(Coord &elt)
{
	this->_coord[0] = elt._coord[0];
	this->_coord[1] = elt._coord[1];
	return *this;
}

int &Coord::operator[](int index)
{
	if (index < 0 || index > 1)
		throw OutOfRangeException();
	return this->_coord[index];
}

const char *Coord::OutOfRangeException::what() const throw()
{
	return "index out of range";
}

void Coord::setCoord(int x, int y)
{
	this->_coord[0] = x;
	this->_coord[1] = y;
}