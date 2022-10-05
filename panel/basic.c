#include <panel.h>

int
main()
{
	WINDOW *my_wins[3];
	PANEL *my_panels[3];
	int lines = 10;
	int cols = 40;
	int y = 2;
	int x = 4;
	int i;

	initscr();
	cbreak();
	noecho();

	/* create windows for the panels */
	my_wins[0] = newwin(lines, cols, y, x);
	my_wins[1] = newwin(lines, cols, y + 1, x + 5);
	my_wins[2] = newwin(lines, cols, y + 2, x + 10);

	/* create borders around the windows so you can see the affect of panels */
	for(i = 0; i < 3; i++)
		box(my_wins[i], 0, 0);

	/* attach a panel to each window */
	my_panels[0] = new_panel(my_wins[0]);
	my_panels[1] = new_panel(my_wins[1]);
	my_panels[2] = new_panel(my_wins[2]);

	/* update the stacking order. 2nd panel will be on top */
	update_panels();

	/* show it on screen */
	doupdate();

	getch();
	endwin();
	return 0;
}
