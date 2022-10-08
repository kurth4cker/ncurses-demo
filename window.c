#include <ncurses.h>

int
main()
{
	WINDOW *win;
	int starty, startx;
	int height, width;
	int maxy, maxx;
	int ch;

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);

	getmaxyx(stdscr, maxy, maxx);
	height = 3;
	width = 10;
	starty = maxy / 2;
	startx = maxx / 2;

	printw("press `q' to exit");
	refresh();

	win = newwin(height, width, starty, startx);
	box(win, 0, 0);
	wrefresh(win);

	while ((ch = getch()) != 'q') {
		wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
		wrefresh(win);

		switch (ch) {
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
