#include "card.h"
#include "rule.h"
#include <QMessageBox>
#include <QIcon>
#include "winDialog.h"

card::card(pips p, suits s, int id, int v, QWidget * parent)
{
    pip = p;
    suit = s;
    if(s == DIAMONDS || s == HEARTS ){
        cardColor = RED;
    }else{
        cardColor = BLACK;
    }
    setParent(parent);
    value = v;
    this->id = id;
    on = NULL;
    faceup = true;
    popUpCard = NULL;
}

QImage card::faces[54];
bool card::initialized = false;
QPoint card::mouseDownOffset; //initialized on mouse down event
QPoint card::startDragPos;
bool card::buttonDown = false;
QPoint card::popUpPos;
card* card::popUpCard;


void card::Initialize(){
    if(initialized){
        return;
    }
    char suit[] = {'c','d', 'h', 's'};
    char pip[] = {'1','2','3','4','5','6','7','8','9','a','b','c','d'};
    int n =0;
    QString fname = ":/cards/c1.bmp";
    for(int s = CLUBS; s<= SPADES; s++){
        fname[8] = suit[s];
        for(int p=ACE; p<=KING; p++){
            fname[9] = pip[p];
            faces[n++] = QImage(fname);
        }
    }

    faces[n] = QImage(":/cards/zCardBack.bmp");
    faces[n+1] = QImage(":/again.png");
    initialized = true;

}
card::~card(){

}

void card::setImage(){
    if(initialized){
        if(faceup){
            QPixmap image = QPixmap::fromImage(faces[value]);
            setPixmap(image);
        }else{
        QPixmap image = QPixmap::fromImage(faces[52]);
        setPixmap(image);
        }
    }

}

bool card::okTodrag(Pile* pile){
     Rule* r1 = new RuleAlternateColors;
     Rule* r2 = new RuleMinusOne;
     return r1->enforce(pile,this) && r2->enforce(pile,this);
 }

void card::winCheck(){
   bool won = true;
   if(piles->value(0)->getType() == FOUNDATION){
    for(int i = 0; i<4; i++){
        if(piles->value(i+12)->frst()){
            if(piles->value(i+12)->frst()->getPip() != KING){
               won = false;
               break;
            }
        }else{
            won = false;
            break;
        }
    }
   }
    if(piles->value(0)->getType() == SFOUNDATION){
        for(int i = 15; i<23; i++){
            if(piles->value(i)->frst()){
                if(piles->value(i)->frst()->getPip() != ACE){
                   won = false;
                   break;
                }
            }else{
                won = false;
                break;
            }
        }
    }
     if(piles->value(0)->getType() == KFOUNDATION){
         for(int i = 9; i<13; i++){
             if(piles->value(i)->frst()){
                 if(piles->value(i)->frst()->getPip() != KING){
                    won = false;
                    break;
                 }
             }else{
                 won = false;
                 break;
             }
         }
     }
     WinDialog* wDlg = new WinDialog(this);
//     QMessageBox msgBox;
//     msgBox.setText("<font face=\"fantasy\" size=\"20pt\" color=\"dark green\"> Well done! </font>");
     wDlg->setWindowIcon(QIcon(QPixmap::fromImage(QImage(":/win.png"))));
     wDlg->setWindowTitle("You won!");
     if(won){
        wDlg->exec();
        history->clear();
     }
}

void card::sequenceCheck(Pile* pile){
    if(pile->getType() == SFOUNDATION){
        RuleKingToAce* r1 = new RuleKingToAce;
        card* king = r1->enforce(pile, this);
        if(king){
            card* c= king;
            for(int i = 15; i< 23; i++){
                if(!piles->value(i)->frst()){
                    while(c){
                        card* aux = c->over;
                        c->on->take(c);
                        piles->value(i)->put(c);
                        c = aux;
                    }
                    history->clear();
                    break;
                }
            }
        }
    }
}

void card::refill(){
    if(on->getType() == DECK && value == 53){
      card* c = piles->value(8)->frst();
      while(c){
          c->on->take(c);
          c->setFaceDown();
          c->setImage();
          piles->value(7)->put(c);
          c = piles->value(8)->frst();
      }
      history = NULL;
    }
}

void card::setPile(Pile* p){
    on = p;
}
void card::mouseDoubleClickEvent(QMouseEvent *e){
    if ( e->button() == Qt::LeftButton ){
        int adjust = 0;
       if(on->getType() == FOUNDATION){
            adjust = 12;
       }else if(on->getType() == KFOUNDATION){
            adjust = 9;
       }

       if(adjust >0 && faceup){
        for(int i=0; i<4; i++){
            if(piles->value(i+adjust)->oktoDrop(this,piles)){
                int cFaceDown = 200;
                if(under){
                    if(!under->faceup){
                        cFaceDown = under->id;
                    }
                }
                Pile* from = on;
                QList<int>* cardsMoved = new QList<int>();
                cardsMoved->append(id);
                this->on->take(this);
                piles->value(i+adjust)->put(this);
                Move m(from,piles->value(i+adjust),cardsMoved,cFaceDown);
                history->push(m);
                winCheck();
                return;
            }
        }

    }
   }
}

void card::mousePressEvent(QMouseEvent* ev){
    buttonDown = false;
    switch (ev->button()) {
    case Qt::LeftButton:
         if(on->getType() == DECK && value == 53){
            refill();
              buttonDown = true;
         }else{
        if(on->getType() == DEAL){
            buttonDown = true;
            Pile* clicked = on;
            card* c = this;
            int i = 0;
            while(clicked->frst()){
                c=clicked->getCards()[0];
                c->setFaceUp();
                clicked->take(c);
                piles->value(i)->put(c);
                i++;
            }
            history->clear();
            return;
        }
        if(on->getType() == DECK && !faceup){
            buttonDown = true;
            piles->value(7)->take(this);
            this->setFaceUp();
            this->setImage();
            piles->value(8)->put(this);
            Pile* from = piles->value(7);
            QList<int>* cardsMoved = new QList<int>();
            cardsMoved->append(id);
            Move m(from,piles->value(8),cardsMoved,id);
            history->push(m);
        }
            startDragPos = pos();
            mouseDownOffset = pos() - ev->globalPos();
            //okToDrag = faceup && pile->canBeDragged(this);
         }
        break;
    default:
        break;
    }
}


void card::mouseMoveEvent(QMouseEvent* ev){

     Rule* r1 = new RuleDeacresingAlternating;
     Rule* r2 = new RuleDeacresingSameSuit;

     if(((on->getType()== FOUNDATION || on->getType()== SPACE || on->getType()== KFOUNDATION) && r1->enforce(this->on,this))
             || (on->getType() == SFOUNDATION && !buttonDown && r2->enforce(this->on,this))
             || (on->getType() == DECK && !buttonDown)
             || (on->getType() == STOCK)){
         card* c = this;
         popUpCard = this;
         int i = 0;
         while(c){
             QPoint point = ev->globalPos() + mouseDownOffset;
             point.setY(point.y()+20*i);
             //QPoint move = point - QPoint(pos().x(), pos().y() + 20*i);
             c->move(point);
             c->raise();
             c = c->over;
             i++;
        }
     }
 }


void card::mouseReleaseEvent(QMouseEvent* ev){
    if(ev->buttons()) return;
    if(popUpCard){
        int cFaceDown = 200;
        if(!faceup){
            cFaceDown = id;
        }else if(under && !under->faceup){
            cFaceDown = under->id;
        }
        Pile* from = on;
        QList<int>* cardsMoved = new QList<int>();
        card* c = popUpCard;
        QPoint posDroped = ev->globalPos() + mouseDownOffset;
        for(int i = 0; i<piles->size();i++){
            if(piles->value(i)->getType() != DECK){
                if(piles->value(i)->getType() != DEAL){
            double px = piles->value(i)->pos.x();
            double py = piles->value(i)->pos.y();
            double allpileY = py + piles->value(i)->getSize()*20 + 70;
            if(posDroped.x() - px < 20 && posDroped.y() < allpileY && posDroped.y() >= py){
               if(piles->value(i)!= popUpCard->on){
                   if(piles->value(i)->oktoDrop(this, piles)){
                       while(c){
                          card* aux = c->over;
                          c->on->take(c);
                          piles->value(i)->put(c);
                          cardsMoved->append(c->id);
                          c = aux;
                      }
                       Move m(from,piles->value(i),cardsMoved,cFaceDown);
                       history->push(m);
                       sequenceCheck(piles->value(i));
                       winCheck();
                       popUpCard = NULL;
                       return;
                   }
                   break;
            }
               break;
            }
        }
    }
        }
        int i = 0;
        while(c){
           card* aux = c->over;
           QPoint back(startDragPos.x(),startDragPos.y()+20*i);
           c->move(back);
           c = aux;
           i++;
       }
        popUpCard = NULL;
        return;
    }

}

