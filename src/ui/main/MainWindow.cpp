#include "MainWindow.h"
#include "../rubik/RubikMenu.h"
#include "../../logic/signalHandling/terminate.h"
#include <cstring>

MainWindow::MainWindow(Window *win) : MenuWindow(win) {
	char *choices[] = {
		(char *) "Rubik's cube",
		(char *) "Exit",
		(char *) NULL,
	};
	
	initMenu(getWindow(), choices);
	this->refresh();
}

MainWindow::~MainWindow() {
}

void MainWindow::chooseOption(const char* choice) {
	if (strcmp(choice, "Exit") == 0) {
		endGamecenter(this);
	} else if (strcmp(choice, "Rubik's cube") == 0) {
		new RubikMenu(this);
	} else {
		fprintf(stderr, "Usage : Invalid option selected\n");
		//TODO: Log the error appropriately
		endGamecenter(this);
	}
}
