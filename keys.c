#include <ncurses.h>

int main()
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	addstr("use arrow keys to go up and down.\n");
	refresh();

	int y, x;
	getyx(stdscr, y, x);

	for (;;) {
		int ch = getch();

		switch (ch) {
		case KEY_UP:
			--y;
			break;
		case KEY_DOWN:
			++y;
			break;
		case KEY_LEFT:
			--x;
			break;
		case KEY_RIGHT:
			++x;
			break;
		case 'q':
			endwin();
			return 0;
		default:
			move(24, 0);
			printw("character pressed is = %3d.\n", ch);
			printw("hopefully it can be printed as '%c'", ch);
			break;
		}

		move(y, x);
		refresh();
	}

	endwin();
}
