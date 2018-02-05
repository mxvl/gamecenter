#include "MainWindow.h"

MainWindow::MainWindow() {
	WINDOW *localWindow = getWindow();
	createMenu(localWindow);
	this->refresh();
}

MainWindow::~MainWindow() {
}

void MainWindow::createMenu(WINDOW *localWindow) {
	wmove(localWindow, 10, 10);
	wprintw(localWindow, "Test reussi");
}