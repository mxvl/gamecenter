#include "MenuWindow.h"
#include <stdlib.h>

MenuWindow::MenuWindow() {
}

MenuWindow::~MenuWindow() {
}

MENU *MenuWindow::createMenu(char *choices[], int nbChoices) {
	ITEM **menuItems;
	
	menuItems = (ITEM **)calloc(nbChoices, sizeof(ITEM *));
	
	for (int i=0; i<nbChoices; i++) {
		menuItems[i] = new_item(choices[i], choices[i]);
	}
	
	return new_menu((ITEM **)menuItems);
}

