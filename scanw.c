#include <string.h>
#include <ncurses.h>

int
main()
{
	char str[80];
	int maxy = getmaxy(stdscr);

	initscr();
	curs_set(0);

	move(15, 20);
	addstr("enter a string: ");
	getstr(str);

	move(maxy - 2, 0);
	addstr("you entered: ");
	attron(A_BOLD);
	addstr(str);

	getch();
	endwin();
}
