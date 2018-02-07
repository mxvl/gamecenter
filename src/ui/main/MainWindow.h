#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ncurses.h>
#include <menu.h>
#include <vector>
#include <string>
#include "../template/Window.h"

class MainWindow : public Window {
public:
	MainWindow();
	virtual ~MainWindow();

private:
	void createMenu(WINDOW *localWindow);
};

#endif /* MAINWINDOW_H */

