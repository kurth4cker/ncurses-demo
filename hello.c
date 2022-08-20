#include <stdlib.h>
#include <curses.h>
#include <signal.h>

int
main()
{
	int num = 0;

	(void)initscr();

	if (has_colors()) {
		start_color();

		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_BLUE, COLOR_BLACK);
		init_pair(3, COLOR_GREEN, COLOR_BLACK);
		init_pair(4, COLOR_WHITE, COLOR_BLACK);
	}

	while(1) {
		int c = getch();
		attrset(COLOR_PAIR(num % 4));
		num++;

		if (c == 'q')
			break;
	}

	endwin();
	return 0;
}
