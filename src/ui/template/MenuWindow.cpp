#include "MenuWindow.h"
#include <stdlib.h>
#include <cstring>

MenuWindow::MenuWindow()
{
}

MenuWindow::~MenuWindow()
{
	unpost_menu(menu);
	for (int i=0; i<menuLenght-1; i++) {
		free_item(items[i]);
	}
	free_menu(menu);
}

MENU *MenuWindow::createMenu(char *choices[], int nbChoices)
{
	items = (ITEM **) calloc(nbChoices, sizeof(ITEM *));

	for (int i = 0; i < nbChoices; i++) {
		items[i] = new_item(choices[i], "");
	}

	menu = new_menu((ITEM **) items);
	menuLenght = nbChoices;
	return menu;
}

void MenuWindow::setMenu(MENU *menu, WINDOW *localWindow, const Dimension &dimension)
{
	set_menu_win(menu, localWindow);
	set_menu_sub(menu, derwin(localWindow, dimension.dy, dimension.dx, (getHeight()-dimension.dy) /2, (getWidth()-dimension.dx) /2));
	set_menu_mark(menu, " * ");
}

void MenuWindow::useMenu() {
	int ch;
	WINDOW *localWindow = getWindow();
	keypad(localWindow, TRUE);
	
	while((ch = wgetch(localWindow)) != 'q') {
		switch(ch) {
		case KEY_DOWN:
			menu_driver(menu, REQ_DOWN_ITEM);
			break;
			
		case KEY_UP:
			menu_driver(menu, REQ_UP_ITEM);
			break;
			
		case 10:
			chooseOption(item_name(current_item(menu)));
			break;
		}
		wrefresh(localWindow);
	}
}

void MenuWindow::chooseOption(const char* choice) {
	if (strcmp(choice, "Exit") == 0) {
		mvwprintw(getWindow(), LINES - 2, 2, "Up and Down arrow keys to navigate (F1 to Exit)");
	}
}