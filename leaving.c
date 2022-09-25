#include <stdlib.h>
#include <ncurses.h>

int
main()
{
	initscr();
	addstr("hello world\n");
	refresh();
	def_prog_mode();
	endwin();
	system("/bin/sh");
	reset_prog_mode();
	refresh();
	addstr("another string");
	refresh();
	endwin();
	return 0;
}
