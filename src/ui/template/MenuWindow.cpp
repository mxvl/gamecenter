#include "MenuWindow.h"
#include <stdlib.h>

MenuWindow::MenuWindow()
{
}

MenuWindow::~MenuWindow()
{
	for (int i=0; i<menuLenght-1; i++) {
		free_item(items[i]);
	}
	free_menu(menu);
}

MENU *MenuWindow::createMenu(char *choices[], int nbChoices)
{
	items = (ITEM **) calloc(nbChoices, sizeof(ITEM *));

	for (int i = 0; i < nbChoices; i++) {
		items[i] = new_item(choices[i], choices[i]);
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