
#ifndef CARD_H
#define CARD_H
#include <QImage>
#include <QLabel>
enum cardColors {BLACK, RED};
enum pips {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum suits {CLUBS, DIAMONDS, HEARTS, SPADES };

class card: public QLabel
{

private:
    static QImage faces[53];
    static bool initialized;
    int value; //0 to 51
    // Card *under
    //Card *over;
    //Pile *pile;

    /*no need in the 1st impl.
     * cardColors color;
     * pips pips
     * suits suit
     * bool faceup
     * bool moving
     * bool oktodrag
     *
     * bool hasMouseDown
     * static QPoint mouseDownOffset //distance to add to mouse pos to mo
     * static QPoint startDragPos;
     * static QT:MouseButtons button down;
     * static QPoint popUppos
     * static Card* popupcard
     * */
public:
    card(int v, QWidget* parent =0);
    card(pips p , suits s, QWidget* parent = 0);
    static void Initialize();
    /*
     * accessors
     *
     *
     * void mousePressEvent(QMOuseEvent * ev);
     * void mouseMoveEvent(QMOuseEvent * ev);
     * void mouseReleaseEvent(QMOuseEvent * ev);
     * void mouseDoubleClickEvent(QMOuseEvent * ev);
     *
     * */
};

//void Shuffle(Card* Deck[], int n);
//choose a random number to pick a card from the deck
//action game triggered
/*
 * if(game) delete game;
 * resize(600,600)
 * setsizepolicy(qsizepolicy(qsizepolicy::minimum,Qsizepolicy::minimum);
 * game = nre klondike
*/
//qsrand(t.elapsed());
#endif // CARD_H
