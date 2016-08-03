#ifndef PILE_H
#define PILE_H
#include <QWidget>
#include <QLabel>


class card;

enum pileType{KFOUNDATION, SFOUNDATION, FOUNDATION, SPACE, STOCK, DEAL,DECK};

class Pile: public QLabel
{

private:
    card* cards[53];
    int size;
    card* first;
    pileType tp;

public:
    QPoint pos;
    pileType getType(){return tp;}
    card** getCards(){return cards;}
    Pile(pileType pt, QPoint position, QWidget* parent);
    ~Pile();
    void put(card* card);
    card* frst(); //returns the first card on the pile
    card* last(){return cards[0];}  //returns the card last in the pile;
    int getSize(){return size;} //return number of cards in the pile
    void take(card* c); // takes a card from the pile
    bool oktoDrop(card* c, QList<Pile*>* piles); //checks if those cards can be dropped in this pile

};
#endif // PILE_H
