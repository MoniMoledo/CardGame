#ifndef GAMES_H
#define GAMES_H
#include "card.h"
#include "move.h"
#include <QStack>

class games: public QWidget
{
public:
    games(QWidget* parent);
    ~games();
    virtual void generateDeck(); //create cards and set its image
    void shuffle(card* deck[], int n); //shuffle the deck
    virtual void setUp()=0; //shuffles the deck, create game piles and place the cards
    virtual void redeal()=0;//starts again the game with a new deck
    virtual void clear()=0;
    QList<Pile*> piles;
    void pushMove(Move m);
    QStack<Move>* getMoves();

protected:
    card* deck[104];
    QStack<Move> history;
};

#endif // GAMES_H
