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
		switch (ch) {
		case 'o':
			attron(A_BOLD);
			break;
		case 'c':
			attroff(A_BOLD);
			break;
		default:
			addch(ch);
		}
	}

	endwin();
}
