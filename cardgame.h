#ifndef CARDGAME_H
#define CARDGAME_H

#include <QMainWindow>
#include "card.h"
#include "games.h"


namespace Ui {
class CardGame;
}

class CardGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit CardGame(QWidget *parent = 0);

    QList<Pile*> piles;
    card* getCard(int id, Pile* on);
    ~CardGame();


private slots:
    void on_action_Redeal_triggered();

    void on_action_Freecell_triggered();

    void on_action_Spider_triggered();

    void on_action_Klondike_triggered();

    void on_action_About_triggered();

    void on_action_Undo_triggered();

    void on_action_Help_triggered();

private:
    Ui::CardGame *ui;
    card* deck[104];
    games* game = NULL;
};

#endif // CARDGAME_H
