#include "MenuWindow.h"
#include <stdlib.h>

MenuWindow::MenuWindow()
{
}

MenuWindow::~MenuWindow()
{
}

MENU *MenuWindow::createMenu(char *choices[], int nbChoices)
{
	ITEM **menuItems;

	menuItems = (ITEM **) calloc(nbChoices, sizeof(ITEM *));

	for (int i = 0; i < nbChoices; i++) {
		menuItems[i] = new_item(choices[i], choices[i]);
	}

	return new_menu((ITEM **) menuItems);
}

void MenuWindow::setMenu(MENU *menu, WINDOW *localWindow, const Dimension &dimension)
{
	set_menu_win(menu, localWindow);
	set_menu_sub(menu, derwin(localWindow, dimension.dy, dimension.dx, (getHeight()-dimension.dy) /2, (getWidth()-dimension.dx) /2));
	set_menu_mark(menu, " * ");
}