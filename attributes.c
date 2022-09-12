#include <stdlib.h>
#include <ncurses.h>

int
main(int argc, char *argv[])
{
	int ch, prev; /* current and previous characters */
	int row;
	FILE *fp;
	int y, x;
	prev = EOF;

	if (argc != 2) {
		printf("usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("cannot open input file");
		exit(1);
	}

	initscr();                    /* start curses mode */
	row = getmaxy(stdscr);
	ch = fgetc(fp);
	while (ch != EOF) {
		getyx(stdscr, y, x);
		if (y == (row - 1)) {
			printw("<-press any key->");
			getch();
			clear();
			move(0, 0);
		}
		if (prev == '/' && ch == '*') {
			attron(A_BOLD);
			getyx(stdscr, y, x);
			move(y, x -1);
			printw("%c%c", '/', ch);
		} else {
			printw("%c", ch);
		}
		refresh();
		if (prev == '*' && ch == '/')
			attroff(A_BOLD);

		prev = ch;
		ch = fgetc(fp);
	}
	endwin();
	fclose(fp);
	exit(0);
}
