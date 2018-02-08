#include "MainWindow.h"

MainWindow::MainWindow()
{
	WINDOW *localWindow = getWindow();
	initMenu(localWindow);
	this->refresh();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initMenu(WINDOW *localWindow)
{
	MENU *menu;
	ITEM *curItem;

	char *choices[] = {
		(char *) "Rubik's cube",
		(char *) "Exit",
		(char *) NULL,
	};
	menu = createMenu(choices, 3);

	Dimension dimension;
	dimension.dy = 6;
	dimension.dx = 30;
	setMenu(menu, localWindow, dimension);

	post_menu(menu);
}