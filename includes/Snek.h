#ifndef SNEK_H
# define SNEK_H

# include <Coord.h>
# include <exception>
# include <vector>

# define UP 'w'
# define DOWN 's'
# define LEFT 'a'
# define RIGHT 'd'

class Snek
{
	public:
		Snek(void);
		Snek(int x, int y, char dir);
		~Snek(void);

		void move(void);

		const int getSize(void) const;
		const Coord getHead(void) const;
		const std::vector<Coord> getBody(void) const;
		const char getDirection(void) const;
		Coord getPrevLastElt(void) const;

		void setSize(int size);
		void setHead(int x, int y);
		void grow(void);
		void setDirection(char dir);
		void setPrevLastElt(int x, int y);

	private:
		int _size;
		Coord _head;
		std::vector<Coord> _body;
		Coord _prev_last_elt;
		char _direction;
	
};

#endif