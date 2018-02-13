#include "RubikMenu.h"
#include "../main/MainWindow.h"
#include "../../logic/signalHandling/terminate.h"
#include "RubikGame.h"
#include <cstring>
#include "../../game/rubik/Cube.h"

RubikMenu::RubikMenu() {
	char *choices[] = {
		(char *) "Play",
		(char *) "Back",
		(char *) NULL,
	};
	
	initMenu(getWindow(), choices);
	this->refresh();
}

RubikMenu::~RubikMenu() {
}

void RubikMenu::chooseOption(const char *choice) {
	if (strcmp(choice, "Back") == 0) {
		delete this;
		new MainWindow;
	} else if (strcmp(choice, "Play") == 0) {
		delete this;
		new RubikGame;
	} else {
		fprintf(stderr, "Usage : Invalid option selected\n");
		//TODO: Log the error appropriately
		delete this;
		endGamecenter();
	}
}