#include "MainWindow.h"
#include "../../logic/signalHandling/terminate.h"
#include <cstring>

MainWindow::MainWindow() {
	WINDOW *localWindow = getWindow();
	initMenu(localWindow);
	this->refresh();

	useMenu();
}

MainWindow::~MainWindow() {
}

void MainWindow::initMenu(WINDOW *localWindow) {
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

void MainWindow::chooseOption(const char* choice) {
	if (strcmp(choice, "Exit") == 0) {
		delete this;
		endGamecenter();
	} else if (strcmp(choice, "Rubik's cube") == 0) {
		
	} else {
		fprintf(stderr, "Usage : Invalid option selected\n");
		// Log the error appropriately
		delete this;
		endGamecenter();
	}
}