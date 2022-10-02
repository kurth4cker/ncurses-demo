#include <stdlib.h>
#include <ncurses.h>

int
main()
{
	int ret;

	initscr();
	curs_set(0);
	noecho();

	addstr("hello world\n");
	refresh();
	getch();

	def_prog_mode();
	endwin();
	ret = system("/bin/sh");
	reset_prog_mode();

	addstr("another string");
	refresh();

	getch();
	endwin();
	if (ret == -1)
		return 1;
	else
		return 0;
}
