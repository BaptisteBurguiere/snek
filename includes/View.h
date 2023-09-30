#ifndef VIEW_H
# define VIEW_H

# include <iostream>

# define BACKGROUND_GREEN "\u001b[42m"
# define BACKGROUND_RED "\u001b[41m"
# define RESET "\u001b[0m"



class View
{
	public:
		View(void);
		View(const unsigned int size);
		~View(void);

		void drawMap(void);

	private:
		const unsigned int _size;
	
};


#endif