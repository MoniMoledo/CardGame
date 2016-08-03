#include "move.h"

Move::Move(Pile* f, Pile* t, QList<int>* cs, int cardFaceDown):
    from(f),
    to(t),
    cards(cs),
    cardFaceDown(cardFaceDown)
{

};

Move::Move(): from(NULL),to(NULL){
};

