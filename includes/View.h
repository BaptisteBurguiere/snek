#ifndef VIEW_H
# define VIEW_H

# include <iostream>
# include <Map.h>

# define BACKGROUND_GREEN "\u001b[42m"
# define BACKGROUND_RED "\u001b[41m"
# define RESET "\u001b[0m"
# define CURSOR_START "\u001b[1000A\u001b[1000D\u001b[1C\u001b[1B"
# define CURSOR_NEXT_LINE "\u001b[1B\u001b[1000D\u001b[1C"



class View
{
	public:
		View(void);
		View(const unsigned int size);
		~View(void);

		void drawMap(void);
		void drawMapContent(const int * map);
		void update(const int *map);
		void displayScore(int score);

	private:
		const unsigned int _size;
	
};


#endif