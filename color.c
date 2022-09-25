#include <ncurses.h>
#include <string.h>

#define print_in_middle(starty,startx,width,string)	wprint_in_middle(stdscr,(starty),(startx),(width),(string))
void wprint_in_middle(WINDOW*, int, int, int, char *string);

int
main()
{
	initscr();
	curs_set(0);
	if (has_colors() == FALSE) {
		endwin();
	        puts("your terminal does not support color");
		return 1;
	}
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);

	attron(COLOR_PAIR(1));
	print_in_middle(LINES / 2, 0, 0, "viola!!! in color...");
	attroff(COLOR_PAIR(1));

	getch();
	endwin();
	return 0;
}

void
wprint_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
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
	mvwprintw(win, y, x, "%s", string);
	refresh();
}
