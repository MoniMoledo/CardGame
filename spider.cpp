#include "spider.h"
#include "pile.h"
#include <QList>
#include "card.h"

spider::spider(QWidget* parent): games(parent)
{
   //setParent(parent);
}
void spider::setUp(){
    shuffle(deck,2);
    //this->parentWidget()->resize(1000,900);
    piles.append(new Pile(SFOUNDATION,QPoint(30,40), parentWidget()));
    piles.append(new Pile(SFOUNDATION,QPoint(120,40), parentWidget()));
    piles.append(new Pile(SFOUNDATION,QPoint(210,40), parentWidget()));
    piles.append(new Pile(SFOUNDATION,QPoint(300,40), parentWidget()));
    piles.append(new Pile(SFOUNDATION,QPoint(390,40), parentWidget()));
    piles.append(new Pile(SFOUNDATION,QPoint(480,40), parentWidget()));
    piles.append(new Pile(SFOUNDATION,QPoint(570,40), parentWidget()));
    piles.append(new Pile(SFOUNDATION,QPoint(660,40), parentWidget()));
    piles.append(new Pile(SFOUNDATION,QPoint(750,40), parentWidget()));
    piles.append(new Pile(SFOUNDATION,QPoint(840,40), parentWidget()));

    piles.append(new Pile(DEAL,QPoint(720,500), parentWidget()));
    piles.append(new Pile(DEAL,QPoint(740,500), parentWidget()));
    piles.append(new Pile(DEAL,QPoint(760,500), parentWidget()));
    piles.append(new Pile(DEAL,QPoint(780,500), parentWidget()));
    piles.append(new Pile(DEAL,QPoint(800,500), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(30,500), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(50,500), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(70,500), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(90,500), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(110,500), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(130,500), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(150,500), parentWidget()));
    piles.append(new Pile(STOCK,QPoint(170,500), parentWidget()));
    placeCards1();

}
void spider::placeCards1(){
    for(int i = 0; i<104;i++ ){
      deck[i]->setFaceDown();
      deck[i]->setImage();
      deck[i]->show();
    }
    for(int i = 4; i<10;i++ ){
      deck[4 + 5*i]->setFaceUp();
      deck[4 + 5*i]->setImage();
      deck[4 + 5*i]->show();
    }
    for(int i = 0; i<4;i++ ){
      deck[50 + i]->setFaceUp();
      deck[50+i]->setImage();
      deck[50+i]->show();
    }
    for(int i = 0; i<5;i++ ){
      piles.value(0)->put(deck[i]);
      piles.value(1)->put(deck[i + 5]);
      piles.value(2)->put(deck[i + 5*2]);
      piles.value(3)->put(deck[i + 5*3]);
      piles.value(4)->put(deck[i + 5*4]);
      piles.value(5)->put(deck[i + 5*5]);
      piles.value(6)->put(deck[i + 5*6]);
      piles.value(7)->put(deck[i + 5*7]);
      piles.value(8)->put(deck[i + 5*8]);
      piles.value(9)->put(deck[i + 5*9]);
    }
    piles.value(0)->put(deck[50]);
    piles.value(1)->put(deck[51]);
    piles.value(2)->put(deck[52]);
    piles.value(3)->put(deck[53]);
    for(int i = 0; i<5;i++ ){
        for(int j = 0; j<10; j++){
          piles.value(i+10)->put(deck[j + 54 + i*10]);
          deck[j + 54 + i*10]->setFaceDown();
        }

    }


}
void spider::redeal(){

    for(int i = 0; i<piles.size(); i++){
        piles.value(i)->~Pile();
    }
    piles.clear();
    history.clear();
    setUp();
}
void spider::generateDeck(){

    //char* suit[] = {'c','d', 'h', 's'};
    pips pip[] = {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

        for(int i = 0; i<13;i++ ){
            deck[i] = new card(pip[i], CLUBS, i,i,parentWidget());
            deck[i]->piles = &piles;
            deck[i]->setHistory(&history);
            //deck[i]->setImage();
            //deck[i]->show();
        }

        for(int i = 13; i<26;i++ ){
            deck[i] = new card(pip[i-13], CLUBS, i,i-13,parentWidget());
            deck[i]->piles = &piles;
            deck[i]->setHistory(&history);
           // deck[i]->setImage();
           // deck[i]->show();
        }
        for(int i = 26; i<39;i++ ){
            deck[i] = new card(pip[i-26], CLUBS, i,i-26,parentWidget());
            deck[i]->piles = &piles;
            deck[i]->setHistory(&history);
            //deck[i]->setImage();
            //deck[i]->show();
        }

        for(int i = 39; i<52;i++ ){

            deck[i] = new card(pip[i-39], CLUBS, i,i-39,parentWidget());
            deck[i]->piles = &piles;
            deck[i]->setHistory(&history);
           // deck[i]->setImage();
            //deck[i]->show();
        }
        for(int i = 52; i<65;i++ ){
            deck[i] = new card(pip[i-52], CLUBS, i,i-52,parentWidget());
            deck[i]->piles = &piles;
            deck[i]->setHistory(&history);
           // deck[i]->setImage();
           // deck[i]->show();
        }

        for(int i = 65; i<78;i++ ){

            deck[i] = new card(pip[i-65], CLUBS, i,i-65,parentWidget());
            deck[i]->piles = &piles;
            deck[i]->setHistory(&history);
           // deck[i]->setImage();
            //deck[i]->show();
        }
        for(int i = 78; i<91;i++ ){
            deck[i] = new card(pip[i-78], CLUBS, i,i-78,parentWidget());
            deck[i]->piles = &piles;
            deck[i]->setHistory(&history);
          //  deck[i]->setImage();
//            deck[i]->show();
        }

        for(int i = 91; i<104;i++ ){

            deck[i] = new card(pip[i-91], CLUBS, i,i-91,parentWidget());
            deck[i]->piles = &piles;
            deck[i]->setHistory(&history);
           // deck[i]->setImage();
            //deck[i]->show();
        }


}

void spider::clear(){
    for(int i = 0; i<piles.size(); i++){
        piles.value(i)->~Pile();
    }
    /*   for(int i = 0; i<104; i++){
           deck[i] = NULL;
       }*/
    piles.clear();
    history.clear();
}
