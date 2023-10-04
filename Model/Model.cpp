#include <Model.h>
#include <iostream>

Model::Model(void) : _size(DEFAULT_MAP_SIZE), _map(Map(DEFAULT_MAP_SIZE)), _snek(Snek()) {}

Model::Model(const unsigned int size) : _size(size), _map(Map(size)), _snek(Snek()) {}

Model::~Model(void) {}

void Model::load(void)
{
	this->_map.load();
	this->_map.setMap(0, 0, HEAD);
	this->generateApple();
}

void Model::destroy(void)
{
	this->_map.destroy();
}

void Model::updateSnek(char &dir)
{
	switch (dir)
	{
		case UP:
			this->_snek.setDirection(UP);
			break;

		case DOWN:
			this->_snek.setDirection(DOWN);
			break;

		case LEFT:
			this->_snek.setDirection(LEFT);
			break;

		case RIGHT:
			this->_snek.setDirection(RIGHT);
			break;

		default:
			break;
	}
	dir = ' ';
	this->_snek.move();
}

int Model::updateMap(void)
{
	Coord head = this->_snek.getHead();
	const int *map = this->_map.getMap();

	if (head[0] < 0 || head[0] >= this->_size
		|| head[1] < 0 || head[1] >= this->_size
		|| map[COORD(head[0], head[1])] == BODY
		|| map[COORD(head[0], head[1])] == HEAD)
		return this->_snek.getSize();

	bool newApple = false;
	if (map[COORD(head[0], head[1])] == APPLE)
	{
		this->_snek.grow();
		if (this->_snek.getSize() == this->_size * this->_size)
			return this->_snek.getSize();
		newApple = true;
	}


	this->_map.setMap(head[0], head[1], HEAD);
	if (newApple)
		this->generateApple();
	else
	{
		Coord prev = this->_snek.getPrevLastElt();
		this->_map.setMap(prev[0], prev[1], EMPTY);
	}
	return -1;


}

void Model::generateApple(void)
{
	while (true)
	{
		int x = rand() % this->_size;
		int y = rand() % this->_size;

		if (this->_map.getMapCoord(x, y) == EMPTY)
		{
			this->_map.setMap(x, y, APPLE);
			return;
		}
	}
}

const int *Model::getMap(void) {return this->_map.getMap();}