#include <ncurses.h>

#define ARRSIZE(x) (sizeof(x)/sizeof(*x))

struct ex {
	char *str;
	char var;
	char *macro_name;
};
typedef struct ex ex_t;

ex_t acs_vars[] = {
	/* description,    SYMBOL in ncurses internal, macro name */
	{"upper left corner               ", 'l', "ACS_ULCORNER"},
	{"lower left corner               ", 'm', "ACS_LLCORNER"},
	{"upper right corner              ", 'k', "ACS_URCORNER"},
	{"lower right corner              ", 'j', "ACS_LRCORNER"},
	{"tee pointing right              ", 't', "ACS_LTEE"},
	{"tee pointing left               ", 'u', "ACS_RTEE"},
	{"tee pointing up                 ", 'v', "ACS_BTEE"},
	{"tee pointing down               ", 'w', "ACS_TTEE"},
	{"horizontal line                 ", 'q', "ACS_HLINE"},
	{"vertical line                   ", 'x', "ACS_VLINE"},
	{"large plus or cross over        ", 'n', "ACS_PLUS"},
	{"scan line 1                     ", 'o', "ACS_S1"},
	{"scan line 3                     ", 'p', "ACS_S3"},
	{"scan line 7                     ", 'r', "ACS_S7"},
	{"scan line 9                     ", 's', "ACS_S9"},
	{"diamond                         ", '`', "ACS_DIAMOND"},
	{"checker board (stipple)         ", 'a', "ACS_CKBOARD"},
	{"degree symbol                   ", 'f', "ACS_DEGREE"},
	{"plus/minus symbol               ", 'g', "ACS_PLMINUS"},
	{"bullet                          ", '~', "ACS_BULLET"},
	{"arrow pointing left             ", ',', "ACS_LARROW"},
	{"arrow pointing right            ", '+', "ACS_RARROW"},
	{"arrow pointing down             ", '.', "ACS_DARROW"},
	{"arrow pointing up               ", '-', "ACS_UARROW"},
	{"board of squares                ", 'h', "ACS_BOARD"},
	{"lantern symbol                  ", 'i', "ACS_LANTERN"},
	{"solid square block              ", '0', "ACS_BLOCK"},
	{"less/equal sign                 ", 'y', "ACS_LEQUAL"},
	{"greater/equal sign              ", 'z', "ACS_GEQUAL"},
	{"pi                              ", '{', "ACS_PI"},
	{"not equal                       ", '|', "ACS_NEQUAL"},
	{"UK pound sign                   ", '}', "ACS_STERLING"},
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
		move(ARRSIZE(acs_vars) + 2, 0);
		addstr("press `q' to exit. another key to repeat");
		attroff(A_BOLD);
		move(0, 0);

		for (i = 0; i < sizeof(acs_vars)/sizeof(*acs_vars); i++) {
			addstr(acs_vars[i].str);
			addch(NCURSES_ACS(acs_vars[i].var));
			printw("    %s", acs_vars[i].macro_name);
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
