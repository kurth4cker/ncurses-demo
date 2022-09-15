#include <ncurses.h>

int
main()
{
	initscr();
	start_color();

	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	printw("a big string which i didn't core to type fully");
	mvchgat(0, 0, -1, A_BLINK, 1, NULL);
	/*
	 * first two parameters specify the position at which to start
	 * third parameter number of characters to update. -1 means till
	 * end of line
	 * forth parameter is normal attribute you wanted to give
	 * to the character
	 * fifth is the color index. it is the index given during the init_pair()
	 * use 0 if you didn't want color
	 * sixth one is always NULL
	 */
	refresh();
	getch();
	endwin();
	return 0;
}
