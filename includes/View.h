#ifndef VIEW_H
# define VIEW_H

# include <iostream>
# include <Map.h>
# include <ncurses.h>

class View
{
	public:
		View(void);
		View(const unsigned int size);
		~View(void);

		void load(void);
		void destroy(void);

		void drawMap(void);
		void drawMapContent(const int * map);
		void update(const int *map);
		void displayScore(int score);

	private:
		const unsigned int _size;
	
};


#endif