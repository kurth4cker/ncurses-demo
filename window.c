#include <ncurses.h>

int
main()
{
	WINDOW *win;
	int startx, starty, width, height;
	int ch;

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

	height = 3;
	width = 10;
	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;

	printw("press `q' to exit");
	refresh();

	win = newwin(height, width, starty, startx);
	box(win, 0, 0);
	wrefresh(win);

	while ((ch = getch()) != 'q') {
		wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
		wrefresh(win);

		switch(ch) {
		case KEY_LEFT:
			startx--;
			break;
		case KEY_RIGHT:
			startx++;
			break;
		case KEY_UP:
			starty--;
			break;
		case KEY_DOWN:
			starty++;
			break;
		}

		mvwin(win, starty, startx);
		box(win, 0, 0);
		wrefresh(win);
	}

	endwin();
}
