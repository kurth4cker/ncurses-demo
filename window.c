#include <ncurses.h>

static WINDOW *create_newwin(int, int, int, int);
static void destroy_win(WINDOW *);

int
main()
{
	WINDOW *my_win;
	int startx, starty, width, height;
	int ch;

	initscr();
	cbreak();
	keypad(stdscr, TRUE);

	height = 3;
	width = 10;
	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;
	printw("press `q' to exit");
	refresh();
	my_win = create_newwin(height, width, starty, startx);

	while ((ch = getch()) != 'q') {
		switch(ch) {
		case KEY_LEFT:
			destroy_win(my_win);
			my_win = create_newwin(height, width, starty, --startx);
			break;
		case KEY_RIGHT:
			destroy_win(my_win);
			my_win = create_newwin(height, width, starty, ++startx);
			break;
		case KEY_UP:
			destroy_win(my_win);
			my_win = create_newwin(height, width, --starty, startx);
			break;
		case KEY_DOWN:
			destroy_win(my_win);
			my_win = create_newwin(height, width, ++starty, startx);
			break;
		}
	}

	endwin();
	return 0;
}

static WINDOW *
create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *win;

	win = newwin(height, width, starty, startx);
	box(win, 0, 0);
	wrefresh(win);

	return win;
}

static void
destroy_win(WINDOW *win)
{
	wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(win);
	delwin(win);
}
