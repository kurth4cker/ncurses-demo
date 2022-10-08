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

	move(3, 0);
	addstr("the pressed key is: ");
	attron(A_BOLD);
	addch(ch);

	while ((ch = getch()) != 'q') {
		if (ch == 'o')
			attron(A_BOLD);
		else if (ch == 'c')
			attroff(A_BOLD);
		else
			addch(ch);
	}

	endwin();
}
