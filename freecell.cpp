#include "freecell.h"
#include <QTime>
#include <QIcon>
#include "pile.h"
#include <QList>
#include "card.h"

freecell::freecell(QWidget *parent):games(parent)
{
  // setParent(parent);
}

void freecell::setUp(){
    shuffle(deck,1);
    piles.append(new Pile(FOUNDATION,QPoint(30,190), parentWidget()));
    piles.append(new Pile(FOUNDATION,QPoint(120,190), parentWidget()));
    piles.append(new Pile(FOUNDATION,QPoint(210,190), parentWidget()));
    piles.append(new Pile(FOUNDATION,QPoint(300,190), parentWidget()));
    piles.append(new Pile(FOUNDATION,QPoint(400,190), parentWidget()));
    piles.append(new Pile(FOUNDATION,QPoint(490,190), parentWidget()));
    piles.append(new Pile(FOUNDATION,QPoint(580,190), parentWidget()));
    piles.append(new Pile(FOUNDATION,QPoint(670,190), parentWidget()));
    piles.append(new Pile(SPACE,QPoint(30,40), parentWidget()));
    piles.append(new Pile(SPACE,QPoint(120,40), parentWidget()));
    piles.append(new Pile(SPACE,QPoint(210,40), parentWidget()));
    piles.append(new Pile(SPACE,QPoint(300,40), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(410,40), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(500,40), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(590,40), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(680,40), parentWidget()));
    placeCards1();
}

void freecell::placeCards1(){

    for(int i = 0; i<6;i++ ){
      piles.value(0)->put(deck[i]);
      piles.value(1)->put(deck[i + 6]);
      piles.value(2)->put(deck[i + 6*2]);
      piles.value(3)->put(deck[i + 6*3]);
      piles.value(4)->put(deck[i + 6*4]);
      piles.value(5)->put(deck[i + 6*5]);
      piles.value(6)->put(deck[i + 6*6]);
      piles.value(7)->put(deck[i + 6*7]);
    }
    piles.value(0)->put(deck[48]);
    piles.value(1)->put(deck[49]);
    piles.value(2)->put(deck[50]);
    piles.value(3)->put(deck[51]);
    for(int i = 0; i<52;i++ ){
       deck[i]->setImage();
       deck[i]->show();
    }

}

void freecell::redeal(){

    for(int i = 0; i<piles.size(); i++){
        piles.value(i)->~Pile();
    }
    piles.clear();
    history.clear();
    setUp();
}

void freecell::clear(){
    for(int i = 0; i<piles.size(); i++){
        piles.value(i)->~Pile();
    }
 /*   for(int i = 0; i<104; i++){
        deck[i] = NULL;
    }*/
    piles.clear();
    history.clear();
}
