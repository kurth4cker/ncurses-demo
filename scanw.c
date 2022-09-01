#include <string.h>
#include <curses.h>

int
main()
{
	char mesg[] = "enter a string: ";
	char str[80];
	int row, col;

	initscr();
	getmaxyx(stdscr, row, col);
	mvprintw(row/2, (col-strlen(mesg))/2,
		 "%s", mesg);
	getstr(str);
	mvprintw(LINES - 2, 0, "you entered: %s", str);
	getch();
	endwin();

	return 0;
}
