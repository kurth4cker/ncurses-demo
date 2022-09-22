#include <string.h>
#include <ncurses.h>

const char *addstrmesg = "string written by addstr";
const char *printwmesg = "string written by printw";

int
main()
{
	int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	mvaddstr(5, 5, addstrmesg);
	mvprintw(10, 5, "%s", printwmesg);

	move(15, 10);
	addstr("write something ");
	addstr("(press `q' to exit): ");
	refresh();
	while ((ch = getch()) != 'q')
		addch(ch);
	endwin();

	return 0;
}
