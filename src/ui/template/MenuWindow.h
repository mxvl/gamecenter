#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "Window.h"
#include <menu.h>

class MenuWindow : public Window {
public:
	MenuWindow();
	virtual ~MenuWindow();
	
protected:
	virtual MENU *createMenu();
	
private:

};

#endif /* MENUWINDOW_H */

