#include "MainWindow.h"
#include "../rubik/RubikMenu.h"
#include "../../logic/signalHandling/terminate.h"
#include <cstring>

MainWindow::MainWindow() {
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
		delete this;
		endGamecenter();
	} else if (strcmp(choice, "Rubik's cube") == 0) {
		delete this;
		new RubikMenu;
	} else {
		fprintf(stderr, "Usage : Invalid option selected\n");
		//TODO: Log the error appropriately
		delete this;
		endGamecenter();
	}
}