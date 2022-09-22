#include <ncurses.h>

int
main()
{
	initscr();
	addstr("hello world");
	refresh();
	getch();
	endwin();

	return 0;
}
