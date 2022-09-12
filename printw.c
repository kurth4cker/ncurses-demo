#include <string.h>
#include <ncurses.h>

const char *mesg = "just a string";

int
main()
{
	int row, col;
	int ch;

	initscr();
	getmaxyx(stdscr, row, col);
	move(row/2, (col-strlen(mesg))/2);
	attron(A_BOLD);
	printw("%s", mesg);
	attroff(A_BOLD);
	mvprintw(row-2, 0,
		 "this screen has %d rows and %d columns\n", row, col);
	printw("try resizing your window and then run this program again");
	move(row/3, col/3);
	refresh();
	do {
		ch = getch();
	} while (ch != 'q');
	endwin();

	return 0;
}
