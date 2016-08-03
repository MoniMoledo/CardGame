#include "games.h"
#include <QTime>
#include <QIcon>
#include "pile.h"
#include <QList>

games::games(QWidget* parent)
{
  setParent(parent);
}
games::~games(){
   for(int i = 0; i<104; i++){
       deck[i] = NULL;
   }
}

void games::shuffle(card *deck[], int n){
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    for(int i = 0; i<52*n;i++ ){
        int r = qrand()%52;
        card *temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void games::generateDeck(){
    //char* suit[] = {'c','d', 'h', 's'};
    pips pip[] = {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    for(int i = 0; i<13;i++ ){
        deck[i] = new card(pip[i], CLUBS, i,i,parentWidget());
        deck[i]->piles = &piles;
        deck[i]->setHistory(&history);
        deck[i]->setImage();
        deck[i]->show();
    }
    for(int i = 13; i<26;i++ ){
        deck[i] = new card(pip[i-13], DIAMONDS, i,i,parentWidget());
        deck[i]->piles = &piles;
        deck[i]->setHistory(&history);
        deck[i]->setImage();
        deck[i]->show();
    }
    for(int i = 26; i<39;i++ ){
        deck[i] = new card( pip[i-26], HEARTS, i,i,parentWidget());
        deck[i]->piles = &piles;
        deck[i]->setHistory(&history);
        deck[i]->setImage();
        deck[i]->show();
    }
    for(int i = 39; i<52 ;i++ ){
        deck[i] = new card(pip[i-39], SPADES, i,i,parentWidget());
        deck[i]->piles = &piles;
        deck[i]->setHistory(&history);
        deck[i]->setImage();
        deck[i]->show();
    }


}

void games::pushMove(Move m){
      history.push(m);
}

QStack<Move>* games::getMoves(){
      return &history;
}
