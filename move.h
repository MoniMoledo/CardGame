#ifndef MOVE_H
#define MOVE_H
#include "pile.h"
#include <QList>


class Move
{
    private:
        Pile* from;
        Pile* to;
        QList<int>* cards;
        int cardFaceDown;
    public:
    Move(Pile* f,Pile* t, QList<int>* cs, int cardFaceDown);
    Move();
    Pile* getFrom(){return from;}
    Pile* getTo(){ return to;}
    QList<int>* getCards(){ return cards;}
    int getCardFaceDown(){return cardFaceDown;}
};


#endif // MOVE_H
