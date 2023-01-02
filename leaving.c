#include <stdlib.h>
#include <ncurses.h>

int main()
{
	int ret;

	initscr();
	curs_set(0);
	noecho();

	addstr("hello world\n");
	getch();

	def_prog_mode();
	endwin();
	ret = system("/bin/sh");
	reset_prog_mode();

	addstr("another string");

	getch();
	endwin();
	return ret == -1;
}
