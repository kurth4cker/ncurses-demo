#include <stdlib.h>
#include <ncurses.h>

int
main()
{
	initscr();
	curs_set(0);
	noecho();

	addstr("hello world\n");
	refresh();
	getch();

	def_prog_mode();
	endwin();
	system("/bin/sh");
	reset_prog_mode();

	addstr("another string");
	refresh();

	getch();
	endwin();
	return 0;
}
