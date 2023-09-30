#include <Model.h>

Model::Model(void) : _size(DEFAULT_MAP_SIZE), _map(Map(DEFAULT_MAP_SIZE)), _snek(Snek())
{
	this->_map.setMap(0, 0, HEAD);
	this->generateApple();
}

Model::Model(const unsigned int size) : _size(size), _map(Map(size)), _snek(Snek())
{
	this->_map.setMap(0, 0, HEAD);
	this->generateApple();
}

Model::~Model(void) {}

void Model::updateSnek(char dir)
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

	this->_snek.move();
}

int Model::updateMap(void)
{
	Coord head = this->_snek.getHead();
	const int *map = this->_map.getMap();

	if (head[0] < 0 || head[0] >= this->_size
		|| head[1] < 0 || head[1] >= this->_size
		|| map[COORD(head[0], head[1])] == BODY)
		return this->_snek.getSize();

	bool newApple = false;
	if (map[COORD(head[0], head[1])] == APPLE)
	{
		this->_snek.grow();
		if (this->_snek.getSize() == this->_size * this->_size)
			return this->_snek.getSize();
		newApple = true;
	}

	// this->_map.setMap()
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