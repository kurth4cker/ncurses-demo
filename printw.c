#include <string.h>
#include <ncurses.h>

const char *mesg = "just a string";

int
main()
{
	int row, col;
	int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

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
	while ((ch = getch()) != 'q')
		addch(ch);
	endwin();

	return 0;
}
