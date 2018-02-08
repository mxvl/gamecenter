#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "Window.h"
#include <menu.h>

class MenuWindow : public Window {
public:
	MenuWindow();
	virtual ~MenuWindow();
	
protected:
	MENU *createMenu(char *choices[], int nbChoices);
	
private:

};

#endif /* MENUWINDOW_H */

