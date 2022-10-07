#include <string.h>
#include <panel.h>

#define NLINES 10
#define NCOLS 40

void init_wins(WINDOW **, int);
void win_show(WINDOW *, char *, int);
void print_in_middle(WINDOW *, int, int, int, char *, chtype);

int
main()
{
	WINDOW *my_wins[3];
	PANEL *my_panels[3];
	PANEL *top;
	int ch;

	/* initialize curses */
	initscr();
	start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/* initialize all the colors */
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);

	init_wins(my_wins, 3);

	/* attach a panel to each window */
	my_panels[0] = new_panel(my_wins[0]);
	my_panels[1] = new_panel(my_wins[1]);
	my_panels[2] = new_panel(my_wins[2]);

	/* set up the user pointers to the next panel */
	set_panel_userptr(my_panels[0], my_panels[1]);
	set_panel_userptr(my_panels[1], my_panels[2]);
	set_panel_userptr(my_panels[2], my_panels[0]);

	/* update the stacking order. 2nd panel will be in top */
	update_panels();

	/* show it on the screen */
	attron(COLOR_PAIR(4));
	mvaddstr(LINES - 2, 0, "use tab to browse through the windows (`q' to exit)");
	attroff(COLOR_PAIR(4));
	doupdate();

	top = my_panels[2];
	while ((ch = getch()) != 'q') {
		switch (ch) {
		case 9:
			top = (PANEL *)panel_userptr(top);
			top_panel(top);
			break;
		}
		update_panels();
		doupdate();
	}

	endwin();
	return 0;
}

/* put all the windows */
void
init_wins(WINDOW **wins, int n)
{
	int x, y, i;
	char label[80];

	y = 2;
	x = 10;
	for (i = 0; i < n; i++) {
		wins[i] = newwin(NLINES, NCOLS, y, x);
		sprintf(label, "window number %d", i + 1);
		win_show(wins[i], label, i + 1);
		y += 3;
		x += 7;
	}
}

/* show the window with a border and a label */
void
win_show(WINDOW *win, char *label, int label_color)
{
	int width;

	width = getmaxx(win);

	box(win, 0, 0);
	mvwaddch(win, 2, 0, ACS_LTEE);
	mvwhline(win, 2, 1, ACS_HLINE, width - 2);
	mvwaddch(win, 2, width - 1, ACS_RTEE);

	print_in_middle(win, 1, 0, width, label, COLOR_PAIR(label_color));
}

void
print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{
	int length, x, y;
	float temp;

	if (win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if (startx != 0)
		x = startx;
	if (starty != 0)
		y = starty;
	if (width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length) / 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwaddstr(win, y, x, string);
	wattroff(win, color);
	refresh();
}
