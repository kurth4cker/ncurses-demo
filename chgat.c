#include <ncurses.h>

int
main()
{
	initscr();
	start_color();

	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	printw("a big string which i didn't core to type fully");
	move(0, 0);
	chgat(-1, A_BLINK, 1, NULL);
	/*
	 * first parameter number of characters to update. -1 means till
	 *    end of line
	 * second parameter is normal attribute you wanted to give
	 *    to the character
	 * third is the color index. it is the index given during the init_pair()
	 *    use 0 if you didn't want color
	 * forth one is always NULL
	 */
	refresh();
	getch();
	endwin();
	return 0;
}
