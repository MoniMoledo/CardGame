#include "cardgame.h"
#include "ui_cardgame.h"
#include "pile.h"
#include "card.h"
#include "freecell.h"
#include "spider.h"
#include "klondike.h"
#include "helpdialog.h"
#include "aboutdialog.h"
#include <QMessageBox>
#include <QIcon>

CardGame::CardGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CardGame)
{
    ui->setupUi(this);
    QPixmap icon = QPixmap::fromImage(QImage(":/icon.png"));
    this->setWindowIcon(QIcon(icon));
    this->setWindowTitle("Solitaire");
    card::Initialize();

}
CardGame::~CardGame()
{

    piles.clear();
    delete ui;
}
void CardGame::on_action_Redeal_triggered()
{
    if(game){
        game->redeal();
    }

}

void CardGame::on_action_Freecell_triggered()
{
        if(game){
            game->clear();
         //   game->~games();
        }
        game = new freecell(ui->centralWidget);
        game->generateDeck();
        game->setUp();
}

void CardGame::on_action_Spider_triggered()
{
    if(game){
        game->clear();
        //game->~games();
    }
    game = new spider(ui->centralWidget);
    game->generateDeck();
    game->setUp();
}

void CardGame::on_action_Klondike_triggered()
{
    if(game){
        game->clear();
       // game->~games();
    }
    game = new klondike(ui->centralWidget);
    game->generateDeck();
    game->setUp();
}


void CardGame::on_action_About_triggered()
{
   AboutDialog *aDialog = new AboutDialog(this);
    aDialog->setWindowIcon(QIcon(QPixmap::fromImage(QImage(":/info.png"))));
    aDialog->setWindowTitle("About");
    aDialog->show();

}

card* CardGame:: getCard(int id, Pile* on){
    for(int i = 0; i< on->getSize(); i++){
        if(on->getCards()[i]->getId() == id){
            return on->getCards()[i];
        }
    }
    return NULL;
}

void CardGame::on_action_Undo_triggered()
{
    if(game){
        if(game->getMoves()){
        if(!game->getMoves()->empty()){
            Move m = game->getMoves()->pop();
            for(int i=0;i<m.getCards()->size();i++){
                int id = m.getCards()->value(i);
                card* c = getCard(id,m.getTo());
                if(m.getCardFaceDown()!=200){
                  if(m.getCardFaceDown()!= m.getCards()->value(0)){
                    card* cFaceDown = getCard(m.getCardFaceDown(),m.getFrom());
                    cFaceDown->setFaceDown();
                    cFaceDown->setImage();
                  }else{
                    card* cFaceDown = getCard(m.getCardFaceDown(),m.getTo());
                    cFaceDown->setFaceDown();
                    cFaceDown->setImage();
                }
              }
                m.getTo()->take(c);
                m.getFrom()->put(c);
            }
        }
    }
    }
}

void CardGame::on_action_Help_triggered()
{
    HelpDialog *hd = new HelpDialog(this);
    hd->setWindowTitle("Help");
    hd->show();
}
