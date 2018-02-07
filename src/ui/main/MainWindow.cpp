#include "MainWindow.h"
#include <cstring>

MainWindow::MainWindow() {
	WINDOW *localWindow = getWindow();
	createMenu(localWindow);
	this->refresh();
}

MainWindow::~MainWindow() {
}

void MainWindow::createMenu(WINDOW *localWindow) {
	char *choices[] = {
		(char *)"Rubik's cube",
		(char *)"Exit",
		(char *)NULL,
	};
	
	ITEM **menuItems;
	int ch, nbChoices;
	MENU *menu;
	ITEM *curItem;
	
	nbChoices = sizeof(choices) / sizeof(choices[0]);
	menuItems = (ITEM **)calloc(nbChoices, sizeof(ITEM *));
	
	for (int i=0; i<nbChoices; i++) {
		menuItems[i] = new_item(choices[i], choices[i]);
	}
	
	menu = new_menu((ITEM **)menuItems);
	set_menu_win(menu, getWindow());
	post_menu(menu);
}