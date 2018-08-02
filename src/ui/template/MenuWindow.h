#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "Window.h"
#include <menu.h>
#include "../../geometry/Dimension.h"

class MenuWindow : public Window {
public:
    MenuWindow(Window *win);
    virtual ~MenuWindow();

protected:
    MENU *createMenu(char *choices[], int nbChoices);
    void setMenu(MENU *menu, WINDOW *localWindow, const Dimension &dimension);
    void useMenu();
    virtual void chooseOption(const char *choice) =0;
    void initMenu(WINDOW *localWindow, char *choices[]);

private:
    MENU *menu;
    int menuLenght;
    ITEM **items;

};

#endif /* MENUWINDOW_H */

