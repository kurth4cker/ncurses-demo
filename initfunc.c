#include <ncurses.h>

int
main()
{
	int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	addstr("type any character to see it in bold");
	ch = getch();

	mvaddstr(3, 0, "the pressed key is: ");
	attron(A_BOLD);
	addch(ch);
	refresh();

	while ((ch = getch()) != 'q') {
		if (ch == 'o')
			attron(A_BOLD);
		else if (ch == 'c')
			attroff(A_BOLD);
		else
			addch(ch);
	}
	endwin();

	return 0;
}
