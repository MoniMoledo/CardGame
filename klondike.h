#ifndef KLONDIKE_H
#define KLONDIKE_H
#include "card.h"
#include "games.h"


class klondike: public games
{
public:
    klondike(QWidget* parent);
    void placeCards1();
    void setUp();
    void redeal();
    void clear();
   // void generateDeck(int n);
};

#endif // KLONDIKE_H
