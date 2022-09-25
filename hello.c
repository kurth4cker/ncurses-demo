#include <ncurses.h>

int
main()
{
	initscr();
	curs_set(0);
	addstr("hello world");
	refresh();
	getch();
	endwin();

	return 0;
}
