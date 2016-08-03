#ifndef SPIDER_H
#define SPIDER_H
#include "card.h"
#include "games.h"

class spider: public games
{
public:
    spider(QWidget* parent);
    void placeCards1();
    void setUp();
    void redeal();
    void generateDeck();
    void clear();
};

#endif // SPIDER_H
