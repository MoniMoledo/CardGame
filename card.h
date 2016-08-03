#ifndef CARD_H
#define CARD_H
#include <QImage>
#include <QLabel>
#include <QMouseEvent>
#include "pile.h"
#include "move.h"
#include <QStack>
#include <QList>
#include <QStack>

enum cardColors {BLACK, RED};
enum pips {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum suits {CLUBS, DIAMONDS, HEARTS, SPADES };

class card: public QLabel
{

private:
    static QImage faces[54];
    static bool initialized;
    static QPoint mouseDownOffset; //initialized on mouse down event
    static QPoint startDragPos;
    static bool buttonDown;
    static QPoint popUpPos;
    static card* popUpCard;
    card* over; //card that is over it on the pile
    card* under; //card that is under it on the pile
    Pile *on;
    pips pip;
    suits suit;
    cardColors cardColor;


    int value; //0 to 51 to get the image of the card
    int id;

public:
    card(pips p, suits s, int v, int id, QWidget* parent);
    ~card();
    bool faceup;
    QList<Pile*>* piles;
    static void Initialize();
    pips getPip(){return pip;}
    suits getSuit(){return suit;}
    cardColors getColor(){return cardColor;}
    card* getOver(){return over;}
    void setOver(card* c){over = c;}
    void setUnder(card* c){under = c;}
    void setPile(Pile* p);
    void setImage();
    int getId(){return id;}
    void mousePressEvent(QMouseEvent* ev);
    void mouseReleaseEvent(QMouseEvent* ev);
    void mouseMoveEvent(QMouseEvent* ev);
    void mouseDoubleClickEvent(QMouseEvent* ev);
    bool okTodrag(Pile* pile); // check if cards can be dragged
    void setFaceUp(){faceup = true; setImage();}
    void setFaceDown(){faceup = false;}
    bool isfaceup(){return faceup;}
    void winCheck();
    void sequenceCheck(Pile* piles); // for spider, checks if a sequence from Ace to King was made. If yes send it to stock pile
    void refill(); //for klondike, when the cards are over on the deck, refill it.
    QStack<Move>* history; //record movements
    void setHistory(QStack<Move>* h){history = h;}
    friend class Pile;

};


#endif // CARD_H
