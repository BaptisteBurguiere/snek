#ifndef COORD_H
# define COORD_H

# include <exception>

class Coord
{
	public:
		Coord(void);
		Coord(int x, int y);
		~Coord(void);

		Coord &operator=(Coord &elt);
		int &operator[](int index);

		class OutOfRangeException : public std::exception
		{
			virtual const char *what() const throw();
		};

		void setCoord(int x, int y);

	private:
		int _coord[2];
};


#endif