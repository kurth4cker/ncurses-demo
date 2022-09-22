#include <ncurses.h>

int
main()
{
	int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	addstr("type any character to see it in bold\n");
	ch = getch();

	if (ch == KEY_F(1)) {
		addstr("F1 key pressed");
	} else {
		addstr("the pressed key is ");
		attron(A_BOLD);
		addch(ch);
		attroff(A_BOLD);
	}
	refresh();

	attron(A_BOLD);
	while ((ch = getch()) != 'q') {
		if (ch == 'o')
			attron(A_BOLD);
		else if (ch == 'c')
			attroff(A_BOLD);
		else
			addch(ch);
	}
	attroff(A_BOLD);
	endwin();

	return 0;
}
