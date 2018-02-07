#include "MenuWindow.h"
#include <stdlib.h>

MenuWindow::MenuWindow() {
}

MenuWindow::~MenuWindow() {
}

MENU *MenuWindow::createMenu() {
	ITEM **menuItems;
	int nbChoices;
	
	char *choices[] = {
		(char *)"Rubik's cube",
		(char *)"Exit",
		(char *)NULL,
	};
	
	nbChoices = sizeof(choices) / sizeof(choices[0]);
	menuItems = (ITEM **)calloc(nbChoices, sizeof(ITEM *));
	
	for (int i=0; i<nbChoices; i++) {
		menuItems[i] = new_item(choices[i], choices[i]);
	}
	
	return new_menu((ITEM **)menuItems);
}

