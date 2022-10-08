#include <ncurses.h>

int
main()
{
	initscr();
	noecho();
	start_color();
	curs_set(0);

	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	addstr("press any key to change following string's attributes");
	attroff(COLOR_PAIR(2));

	attron(A_BLINK);
	move(3, 0);
	addstr("a big string which i didn't core to type fully");
	attroff(A_BLINK);

	getch();
	move(3, 0);
	chgat(-1, A_BOLD, 1, NULL);
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
}
