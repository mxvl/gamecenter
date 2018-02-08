#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include "Window.h"
#include <menu.h>
#include "../../geometry/Dimension.h"

class MenuWindow : public Window {
public:
    MenuWindow();
    virtual ~MenuWindow();

protected:
    MENU *createMenu(char *choices[], int nbChoices);
    void setMenu(MENU *menu, WINDOW *localWindow, const Dimension &dimension);

private:

};

#endif /* MENUWINDOW_H */

