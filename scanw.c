#include <string.h>
#include <ncurses.h>

const char *mesg = "enter a string: ";

int
main()
{
	char str[80];

	initscr();

	mvaddstr(15, 20, mesg);
	getstr(str);

	move(LINES - 2, 0);
	addstr("you entered: ");
	addstr(str);

	getch();
	endwin();
	return 0;
}
