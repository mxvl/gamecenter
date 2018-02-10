#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ncurses.h>
#include <menu.h>
#include "../template/MenuWindow.h"

class MainWindow : public MenuWindow {
public:
	MainWindow();
	virtual ~MainWindow();

protected:
	virtual void chooseOption(const char *choice);

private:
	void initMenu(WINDOW *localWindow);
};

#endif /* MAINWINDOW_H */

