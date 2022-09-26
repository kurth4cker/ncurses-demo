#include <ncurses.h>

int
main()
{
	initscr();

	printw("upper left corner               "); addch(ACS_ULCORNER); printw("\n");
	printw("lower left corner               "); addch(ACS_LLCORNER); printw("\n");
	printw("lower right corner              "); addch(ACS_LRCORNER); printw("\n");
	printw("tee pointing right              "); addch(ACS_LTEE); printw("\n");
	printw("tee pointing left               "); addch(ACS_RTEE); printw("\n");
	printw("tee pointing up                 "); addch(ACS_BTEE); printw("\n");
	printw("tee pointing down               "); addch(ACS_TTEE); printw("\n");
	printw("horizontal line                 "); addch(ACS_HLINE); printw("\n");
	printw("vertical line                   "); addch(ACS_VLINE); printw("\n");
	printw("large plus or cross over        "); addch(ACS_PLUS); printw("\n");
	printw("scan line 1                     "); addch(ACS_S1); printw("\n");
	printw("scan line 3                     "); addch(ACS_S3); printw("\n");
	printw("scan line 7                     "); addch(ACS_S7); printw("\n");
	printw("scan line 9                     "); addch(ACS_S9); printw("\n");
	printw("diamond                         "); addch(ACS_DIAMOND); printw("\n");
	printw("checker board (stipple)         "); addch(ACS_CKBOARD); printw("\n");
	printw("degree symbol                   "); addch(ACS_DEGREE); printw("\n");
	printw("plus/minus symbol               "); addch(ACS_PLMINUS); printw("\n");
	printw("bullet                          "); addch(ACS_BULLET); printw("\n");
	printw("arrow pointing left             "); addch(ACS_LARROW); printw("\n");
	printw("arrow pointing right            "); addch(ACS_RARROW); printw("\n");
	printw("arrow pointing down             "); addch(ACS_DARROW); printw("\n");
	printw("arrow pointing up               "); addch(ACS_UARROW); printw("\n");
	printw("board of squares                "); addch(ACS_BOARD); printw("\n");
	printw("lantern symbol                  "); addch(ACS_LANTERN); printw("\n");
	printw("solid square block              "); addch(ACS_BLOCK); printw("\n");
	printw("less/equal sign                 "); addch(ACS_LEQUAL); printw("\n");
	printw("greater/equal sign              "); addch(ACS_GEQUAL); printw("\n");
	printw("pi                              "); addch(ACS_PI); printw("\n");
	printw("not equal                       "); addch(ACS_NEQUAL); printw("\n");
	printw("UK pound sign                   "); addch(ACS_STERLING); printw("\n");

	refresh();
	getch();
	endwin();
	return 0;
}
