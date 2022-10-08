#include <string.h>
#include <ncurses.h>

const char *mesg = "enter a string: ";

int
main()
{
	char str[80];

	initscr();

	move(15, 20);
	addstr("enter a string: ");
	getstr(str);

	curs_set(0);
	move(LINES - 2, 0);
	addstr("you entered: ");
	attron(A_BOLD);
	addstr(str);

	getch();
	endwin();
}
