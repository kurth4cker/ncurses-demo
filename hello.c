#include <stdlib.h>
#include <curses.h>
#include <signal.h>

int
main()
{
	int c;

	(void)initscr();

	do {
		c = getch();
	} while (c != 'q');

	endwin();
	return 0;
}
