#include <ncurses.h>

typedef struct {
	chtype ls, rs, ts, bs;
	chtype tl, tr, bl, br;
} WIN_BORDER;

typedef struct {
	int startx, starty;
	int height, width;
	WIN_BORDER border;
} WIN;

static void init_win_params(WIN *);
static WIN *print_win_params(WIN *);
static void create_box(WIN *, bool);

int
main()
{
	WIN win;
	int ch;

	initscr();
	start_color();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	init_win_params(&win);
	print_win_params(&win);

	attron(COLOR_PAIR(1));
	mvprintw(0, 0, "press `q' to exit");
	refresh();
	attroff(COLOR_PAIR(1));

	create_box(&win, TRUE);
	while ((ch = getch()) != 'q') {
		switch (ch) {
		case KEY_LEFT:
			create_box(&win, FALSE);
			--win.startx;
			create_box(&win, TRUE);
			break;
		case KEY_RIGHT:
			create_box(&win, FALSE);
			++win.startx;
			create_box(&win, TRUE);
			break;
		case KEY_UP:
			create_box(&win, FALSE);
			--win.starty;
			create_box(&win, TRUE);
			break;
		case KEY_DOWN:
			create_box(&win, FALSE);
			++win.starty;
			create_box(&win, TRUE);
			break;
		}

		print_win_params(&win);
		refresh();
	}

	endwin();
	return 0;
}

static void
init_win_params(WIN *winptr)
{
	winptr->height = 3;
	winptr->width = 10;
	winptr->starty = (LINES - winptr->height) / 2;
	winptr->startx = (COLS - winptr->width) / 2;

	winptr->border.ls = '|';
	winptr->border.rs = '|';
	winptr->border.ts = '-';
	winptr->border.bs = '-';
	winptr->border.tl = '+';
	winptr->border.tr = '+';
	winptr->border.bl = '+';
	winptr->border.br = '+';
}

static WIN *
print_win_params(WIN *winptr)
{
	mvprintw(2, 0, "width: %d", winptr->width);
	mvprintw(3, 0, "height: %d", winptr->height);
	mvprintw(5, 0, "positions: %d %d", winptr->starty, winptr->startx);

	return winptr;
}

static void
create_box(WIN *winptr, bool flag)
{
	int i, j;
	int x, y, w, h;

	x = winptr->startx;
	y = winptr->starty;
	w = winptr->width;
	h = winptr->height;

	if (flag == TRUE) {
		mvaddch(y, x, winptr->border.tl);
                mvaddch(y, x + w, winptr->border.tr);
                mvaddch(y + h, x, winptr->border.bl);
                mvaddch(y + h, x + w, winptr->border.br);
                mvhline(y, x + 1, winptr->border.ts, w - 1);
                mvhline(y + h, x + 1, winptr->border.bs, w - 1);
                mvvline(y + 1, x, winptr->border.ls, h - 1);
                mvvline(y + 1, x + w, winptr->border.rs, h - 1);
	} else {
		for (j = y; j <= y + h; j++)
			for (i = x; i <= x + w; i++)
				mvaddch(j, i, ' ');
	}
}
