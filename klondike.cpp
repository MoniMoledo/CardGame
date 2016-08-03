#include "klondike.h"
#include "pile.h"
#include <QList>
#include "card.h"

klondike::klondike(QWidget* parent): games(parent)
{

}
void klondike::setUp(){
    shuffle(deck,1);
    piles.append(new Pile(KFOUNDATION,QPoint(60,190), parentWidget()));
    piles.append(new Pile(KFOUNDATION,QPoint(170,190), parentWidget()));
    piles.append(new Pile(KFOUNDATION,QPoint(280,190), parentWidget()));
    piles.append(new Pile(KFOUNDATION,QPoint(390,190), parentWidget()));
    piles.append(new Pile(KFOUNDATION,QPoint(500,190), parentWidget()));
    piles.append(new Pile(KFOUNDATION,QPoint(610,190), parentWidget()));
    piles.append(new Pile(KFOUNDATION,QPoint(720,190), parentWidget()));

    piles.append(new Pile(DECK,QPoint(40,40), parentWidget()));
    piles.append(new Pile(DECK,QPoint(150,40), parentWidget()));

    piles.append(new Pile(STOCK,QPoint(410,40), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(500,40), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(590,40), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(680,40), parentWidget()));
    placeCards1();

}
void klondike::placeCards1(){
    int t =0;
        for(int i=0; i<7; i++){
         for(int j=0; j<i+1; j++, t++){
          piles.value(i)->put(deck[t]);
          if(j!=i){
              deck[t]->setFaceDown();
              deck[t]->setImage();
          }else{
              deck[t]->setFaceUp();
              deck[t]->setImage();
          }
    }
  }
        deck[52] = new card(ACE, DIAMONDS, 52, 53,parentWidget());
        deck[52]->piles = &piles;
        deck[52]->setImage();
        deck[52]->show();
        piles.value(7)->put(deck[52]);
        for(int i=28; i<52; i++){
            piles.value(7)->put(deck[i]);
            deck[i]->setFaceDown();
            deck[i]->setImage();
        }


}
void klondike::redeal(){
    for(int i = 0; i<piles.size(); i++){
        piles.value(i)->~Pile();
    }
    piles.clear();
    history.clear();
    setUp();
}
void klondike::clear(){
    for(int i = 0; i<piles.size(); i++){
        piles.value(i)->~Pile();
    }
    /*   for(int i = 0; i<104; i++){
           deck[i] = NULL;
       }*/
    piles.clear();
    history.clear();
}
