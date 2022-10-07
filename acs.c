#include <ncurses.h>

struct ex {
	char *str;
	char acsvar;
};
typedef struct ex ex_t;

ex_t acs_vars[] = {
	{"upper left corner               ", 'l'},
	{"lower left corner               ", 'm'},
	{"upper right corner              ", 'k'},
	{"lower right corner              ", 'j'},
	{"tee pointing right              ", 't'},
	{"tee pointing left               ", 'u'},
	{"tee pointing up                 ", 'v'},
	{"tee pointing down               ", 'w'},
	{"horizontal line                 ", 'q'},
	{"vertical line                   ", 'x'},
	{"large plus or cross over        ", 'n'},
	{"scan line 1                     ", 'o'},
	{"scan line 3                     ", 'p'},
	{"scan line 7                     ", 'r'},
	{"scan line 9                     ", 's'},
	{"diamond                         ", '`'},
	{"checker board (stipple)         ", 'a'},
	{"degree symbol                   ", 'f'},
	{"plus/minus symbol               ", 'g'},
	{"bullet                          ", '~'},
	{"arrow pointing left             ", ','},
	{"arrow pointing right            ", '+'},
	{"arrow pointing down             ", '.'},
	{"arrow pointing up               ", '-'},
	{"board of squares                ", 'h'},
	{"lantern symbol                  ", 'i'},
	{"solid square block              ", '0'},
	{"less/equal sign                 ", 'y'},
	{"greater/equal sign              ", 'z'},
	{"pi                              ", '{'},
	{"not equal                       ", '|'},
	{"UK pound sign                   ", '}'},
};

int
main()
{
        size_t i;
	int ch;

	initscr();
	curs_set(0);
	noecho();

	while ((ch = getch()) != 'q') {
		clear();
		attron(A_BOLD);
		move(sizeof(acs_vars)/sizeof(*acs_vars) + 2, 0);
		addstr("press `q' to exit. another key to repeat");
		attroff(A_BOLD);
		move(0, 0);

		for (i = 0; i < sizeof(acs_vars)/sizeof(*acs_vars); i++) {
			addstr(acs_vars[i].str);
			addch(NCURSES_ACS(acs_vars[i].acsvar));
			addch('\n');
			ch = getch();
			if (ch == 'q') {
				endwin();
				return 0;
			}
		}

		attron(A_BOLD);
		addstr("finished");
		attroff(A_BOLD);
	}

	refresh();
	getch();
	endwin();
	return 0;
}
