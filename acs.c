#include <ncurses.h>

int
main()
{
	initscr();
	curs_set(0);
	noecho();

	addstr("upper left corner               ");
	addch(ACS_ULCORNER);
	addch('\n');

	addstr("lower left corner               ");
	addch(ACS_LLCORNER);
	addch('\n');

	addstr("lower right corner              ");
	addch(ACS_LRCORNER);
	addch('\n');

	addstr("tee pointing right              ");
	addch(ACS_LTEE);
	addch('\n');

	addstr("tee pointing left               ");
	addch(ACS_RTEE);
	addch('\n');

	addstr("tee pointing up                 ");
	addch(ACS_BTEE);
	addch('\n');

	addstr("tee pointing down               ");
	addch(ACS_TTEE);
	addch('\n');

	addstr("horizontal line                 ");
	addch(ACS_HLINE);
	addch('\n');

	addstr("vertical line                   ");
	addch(ACS_VLINE);
	addch('\n');

	addstr("large plus or cross over        ");
	addch(ACS_PLUS);
	addch('\n');

	addstr("scan line 1                     ");
	addch(ACS_S1);
	addch('\n');

	addstr("scan line 3                     ");
	addch(ACS_S3);
	addch('\n');

	addstr("scan line 7                     ");
	addch(ACS_S7);
	addch('\n');

	addstr("scan line 9                     ");
	addch(ACS_S9);
	addch('\n');

	addstr("diamond                         ");
	addch(ACS_DIAMOND);
	addch('\n');

	addstr("checker board (stipple)         ");
	addch(ACS_CKBOARD);
	addch('\n');

	addstr("degree symbol                   ");
	addch(ACS_DEGREE);
	addch('\n');

	addstr("plus/minus symbol               ");
	addch(ACS_PLMINUS);
	addch('\n');

	addstr("bullet                          ");
	addch(ACS_BULLET);
	addch('\n');

	addstr("arrow pointing left             ");
	addch(ACS_LARROW);
	addch('\n');

	addstr("arrow pointing right            ");
	addch(ACS_RARROW);
	addch('\n');

	addstr("arrow pointing down             ");
	addch(ACS_DARROW);
	addch('\n');

	addstr("arrow pointing up               ");
	addch(ACS_UARROW);
	addch('\n');

	addstr("board of squares                ");
	addch(ACS_BOARD);
	addch('\n');

	addstr("lantern symbol                  ");
	addch(ACS_LANTERN);
	addch('\n');

	addstr("solid square block              ");
	addch(ACS_BLOCK);
	addch('\n');

	addstr("less/equal sign                 ");
	addch(ACS_LEQUAL);
	addch('\n');

	addstr("greater/equal sign              ");
	addch(ACS_GEQUAL);
	addch('\n');

	addstr("pi                              ");
	addch(ACS_PI);
	addch('\n');

	addstr("not equal                       ");
	addch(ACS_NEQUAL);
	addch('\n');

	addstr("UK pound sign                   ");
	addch(ACS_STERLING);
	addch('\n');

	refresh();
	getch();
	endwin();
	return 0;
}
