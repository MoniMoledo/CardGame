
#include "card.h"
#include "rule.h"

Pile::Pile(pileType pt, QPoint position, QWidget* parent)
{
    setParent(parent);
    pos = position;
    size = 0;
    tp = pt;
    first = NULL;


    setFrameShape(Box);
    setLineWidth(2);
    resize(71,96);
    move(pos);
    //palette().setColor(BACKGROUND_ROLE,BLACK);
    show();

}

Pile::~Pile()
{
   for(int i = 0; i < size; i++){
      cards[i]->clear();
   }
   first = NULL;
   size = 0;

}
card* Pile::frst(){
    return first;
}

bool Pile::oktoDrop(card*c, QList<Pile*>* piles){
    if(tp == SPACE && (size > 0 || c->getOver())){
        return false;
    }
    if(tp == STOCK && !c->getOver()){
        Rule* r1 = new RulePlusOne;
        Rule* r2 = new RuleIsAce;
        return r1->enforce(this,c) || r2->enforce(this,c);
    }else if(tp == STOCK && c->getOver()){
        return false;
    }
    if(tp == FOUNDATION){
        Rule* r1 = new RuleAlternateColors;
        Rule* r2 = new RuleMinusOne;
        RuleMaxCards* r3 = new RuleMaxCards;
        return r1->enforce(this,c) && r2->enforce(this,c) && r3->enforce(piles,c);
    }
    if(tp == SFOUNDATION){
        Rule* r1 = new RuleAlternateColors;
        Rule* r2 = new RuleMinusOne;
        Rule* r3 = new RuleSameSuit;
        return (r1->enforce(this,c) && r2->enforce(this,c)) ||
                (r3->enforce(this,c) && r2->enforce(this,c));
    }
    if(tp == KFOUNDATION){
        Rule* r1 = new RuleAlternateColors;
        Rule* r2 = new RuleMinusOne;
        Rule* r3 = new RuleJustKing;
        return r1->enforce(this,c) && r2->enforce(this,c)&& r3->enforce(this,c);
    }
    return true;

}

void Pile::put(card* c){
    if(size == 0){
       cards[size] = c;
       c->setUnder(NULL);
       size++;
       first = c;
       c->setPile(this);
       c->setOver(NULL);
       c->move(pos);
       c->raise();
    }else{
    cards[size] = c;
    cards[size-1]->setOver(c);
    c->setUnder(cards[size-1]);
    size++;
    first = c;
    c->setPile(this);
    c->setOver(NULL);
    c->move(QPoint(pos.x(),pos.y()+20*(size-1)));
    if(tp == STOCK){
        c->move(pos);
    }
    if(tp == DEAL){
        c->move(pos);
    }
    if(tp == DECK){
        c->move(pos);
    }
    c->raise();
    resize(71,96);
    }
}

void Pile::take(card* c){
    if(size == 1){
        if(cards[0]->getId() == c->getId()){
            cards[0] = NULL;
            size--;
            first = NULL;
        }
    }else{
    for(int i = 0; i <size; i++){
        if(cards[i]){
            if(cards[i]->getId() == c->getId()){
                for(int j = i; j<size-1; j++){
                    cards[j] = cards[j+1];
                }
                //cards[i] = NULL;
                size--;
                first = cards[size-1];
                first->setOver(NULL);
                if(!first->isfaceup() && getType()!=DECK){
                    first->setFaceUp();
                    first->setImage();
                }
            }
        }

    }
    }
}
