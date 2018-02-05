#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

class Window {
public:
	Window();
	virtual ~Window();

protected:
	WINDOW *getWindow();
	void refresh();

private:
	int height, width, starty, startx;
	WINDOW *window;
	WINDOW *createNewWindow();
};

#endif /* WINDOW_H */

