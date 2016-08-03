#ifndef FREECELL_H
#define FREECELL_H

#include "card.h"
#include "games.h"

class freecell: public games
{
public:
    freecell(QWidget *parent);

    void placeCards1();
    void setUp();
    void redeal();
    void clear();
};

#endif // FREECELL_H
