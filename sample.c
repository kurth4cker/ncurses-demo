#include <ncurses.h>

int
main()
{
	int ch;
	int num = 0;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();

	if (has_colors()) {
		start_color();

		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	}

	while (ch != 'q') {
		attrset(COLOR_PAIR(num % 3 + 1));
		ch = getch();
		addch(ch);
		num++;
	}
	endwin();

	return 0;
}
