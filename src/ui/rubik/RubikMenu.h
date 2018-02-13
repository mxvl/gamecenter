#ifndef RUBIKMENU_H
#define RUBIKMENU_H

#include "../template/MenuWindow.h"

class RubikMenu : public MenuWindow {
public:
	RubikMenu();
	virtual ~RubikMenu();

protected:
	virtual void chooseOption(const char *choice);

private:
};

#endif /* RUBIKMENU_H */

