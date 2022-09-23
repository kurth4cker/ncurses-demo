#include <stdio.h>
#include <ncurses.h>

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char *choices[] = {
	"choice 1",
	"choice 2",
	"choice 3",
	"choice 4",
	"exit",
};
int n_choices = sizeof(choices) / sizeof(char *);

static void print_menu(WINDOW *, int);

int
main()
{
	WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	clear();
	noecho();
	cbreak();

	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	addstr("use arrow keys to go up and down. press enter to select an choice");
	refresh();
	print_menu(menu_win, highlight);
	while (1) {
		c = wgetch(menu_win);
		switch (c) {
		case KEY_UP:
			 if(highlight == 1)
				 highlight = n_choices;
			 else
				 --highlight;
			 break;
		case KEY_DOWN:
			if(highlight == n_choices)
				highlight = 1;
			else
				++highlight;
			break;
		case 10:
			choice = highlight;
			break;
		case 'q':
			endwin();
			return 0;
		default:
			mvprintw(24, 0,
				 "Character pressed is = %3d. "
				 "Hopefully it can be printed as '%c'",
				 c, c);
			refresh();
			break;
		}
		print_menu(menu_win, highlight);
		if (choice != 0)
			break;
	}
	mvprintw(23, 0, "you choose \'%s\'.", choices[choice - 1]);
	mvprintw(24, 0, "it's number is %d", choice);
	clrtoeol();
	refresh();
	getch();
	endwin();
	return 0;
}

void
print_menu(WINDOW *menu_win, int highlight)
{
        int x, y, i;

        x = 2;
        y = 2;
        box(menu_win, 0, 0);
        for(i = 0; i < n_choices; ++i)
        {       if(highlight == i + 1) /* High light the present choice */
                {       wattron(menu_win, A_REVERSE);
                        mvwaddstr(menu_win, y, x, choices[i]);
                        wattroff(menu_win, A_REVERSE);
                }
                else
                        mvwaddstr(menu_win, y, x, choices[i]);
                ++y;
        }
        wrefresh(menu_win);
}
