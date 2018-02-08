#include "MainWindow.h"

MainWindow::MainWindow() {
	WINDOW *localWindow = getWindow();
	initMenu(localWindow);
	this->refresh();
}

MainWindow::~MainWindow() {
}

void MainWindow::initMenu(WINDOW *localWindow) {
	MENU *menu;
	ITEM *curItem;
        
	char *choices[] = {
		(char *)"Rubik's cube",
		(char *)"Exit",
		(char *)NULL,
	};
	
	menu = createMenu(choices, 3);
	set_menu_win(menu, localWindow);
	set_menu_sub(menu, derwin(localWindow, 6, 30, (getHeight()/2 - 3), (getWidth()/2 - 15)));
	set_menu_mark(menu, " * ");
	post_menu(menu);
}