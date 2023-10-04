#include <View.h>

View::View(void) : _size(10) {}

View::View(const unsigned int size) : _size(size) {}

View::~View(void) {}

void View::load(void)
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_RED);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
}

void View::destroy(void)
{
	endwin();
}

void View::drawMap(void)
{
	WINDOW *boite= subwin(stdscr, this->_size + 2, this->_size * 2 + 2, 0, 0);
    wborder(boite, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(boite);
}

void View::drawMapContent(const int *map)
{
	for (int j = 0; j < this->_size; ++j)
	{
		for (int i = 0; i < this->_size * 2; i += 2)
		{
			move(j + 1, i + 1);
			switch (map[COORD(i / 2, j)])
			{
				case EMPTY:
					addch(' ');
					move(j + 1, i + 2);
					addch(' ');
					break;

				case HEAD: case BODY:
					attron(COLOR_PAIR(2));
					addch(' ');
					move(j + 1, i + 2);
					addch(' ');
					attroff(COLOR_PAIR(2));
					break;

				case APPLE:
					attron(COLOR_PAIR(1));
					addch(' ');
					move(j + 1, i + 2);
					addch(' ');
					attroff(COLOR_PAIR(1));
					break;

				default:
					break;
			}
		}
	}
}

void View::update(const int *map)
{
	clear();
	this->drawMap();
	this->drawMapContent(map);
	move(this->_size + 2, 0);
	refresh();
}

void View::displayScore(int score)
{
	clear();
	move(0, 0);
	printw("Your score: %d", score);
	refresh();
}