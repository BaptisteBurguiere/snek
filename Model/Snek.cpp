#include <Snek.h>

Snek::Snek(void)
{
	this->_size = 0;
	this->setHead(0, 0);
	this->_direction = RIGHT;
}

Snek::Snek(int x, int y, char dir)
{
	this->_size = 0;
	this->setHead(x, y);
	this->_direction = dir;
}

Snek::~Snek(void) {}

void Snek::move(void)
{
	if (this->_size > 0)
	{
		this->_prev_last_elt = this->_body.back();
		for (int i = this->_size - 1; i > 0; --i)
			this->_body[i] = this->_body[i - 1];
		this->_body[0] = this->_head;
	}
	else
		this->_prev_last_elt = this->_head;

	switch (this->_direction)
	{
		case UP:
			this->_head[1] -= 1;
			break;

		case DOWN:
			this->_head[1] += 1;
			break;

		case LEFT:
			this->_head[0] -= 1;
			break;

		case RIGHT:
			this->_head[0] += 1;
			break;
	}
}

const int Snek::getSize(void) const {return this->_size;}

const Coord Snek::getHead(void) const {return this->_head;}

const std::vector<Coord> Snek::getBody(void) const {return this->_body;}

const char Snek::getDirection(void) const {return this->_direction;}

Coord Snek::getPrevLastElt(void) const {return this->_prev_last_elt;}

void Snek::setSize(int size) {this->_size = size;}

void Snek::setHead(int x, int y) {this->_head.setCoord(x, y);}

void Snek::grow(void)
{
	this->_body.push_back(this->_prev_last_elt);
	this->_size++;
}

void Snek::setDirection(char dir) {this->_direction = dir;}

void Snek::setPrevLastElt(int x, int y) {this->_prev_last_elt.setCoord(x, y);}