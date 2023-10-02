#ifndef MAP_H
# define MAP_H

# include <Coord.h>
# include <exception>

# define DEFAULT_MAP_SIZE 10
# define EMPTY 0
# define HEAD 1
# define BODY 2
# define APPLE 3
# define COORD(x, y) (x + (y * this->_size))

class Map
{
	public:
		Map(const unsigned int size);
		~Map(void);

		class OutOfRangeException : public std::exception
		{
			virtual const char *what() const throw();
		};

		void load(void);
		void destroy(void);

		const unsigned int getSize(void) const;
		const int *getMap(void) const;
		const int getMapCoord(int x, int y) const;
		void setMap(int x, int y, int value);

	private:
		const unsigned int _size;
		int *_map;
};


#endif