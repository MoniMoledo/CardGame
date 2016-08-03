#include "rule.h"
#include "pile.h"
#include "card.h"
#include "math.h"


bool RuleAlternateColors::enforce(Pile *pile, card *card){
    if(pile->frst()){
            if(pile->frst()->getColor() != card->getColor()){
                return true;
            }else{
                return false;
            }
    }
    return true;
}

bool RuleSameSuit::enforce(Pile *pile, card *card){
    if(pile->frst()){
            if(pile->frst()->getSuit() == card->getSuit()){
                return true;
            }else{
                return false;
            }
    }
    return true;
}
bool RuleJustKing::enforce(Pile *pile, card *card){
    if(!pile->frst()){
      if(card->getPip() == KING){
          return true;
      }else{
          return false;
      }
    }
    return true;
}

bool RuleMaxCards::enforce(QList<Pile*>* piles, card* cd){
    int nToMove = 0;
    card* c = cd;
    while(c){
      nToMove++;
      c = c->getOver();
    }
    int nFreeCol = 0;
    for(int i =0; i<16; i++){
      if(piles->value(i)->getType() == FOUNDATION){
          if(!piles->value(i)->frst()){
              nFreeCol++;
          }
      }
    }
    int nFreeCell = 0;
    for(int i =0; i<16; i++){
      if(piles->value(i)->getType() == SPACE){
          if(!piles->value(i)->frst()){
              nFreeCell++;
          }
      }
    }
    return nToMove <= ((1 + nFreeCell) * (pow(2,nFreeCol)));
}

bool RuleIsAce::enforce(Pile *pile, card* card){
    if(!pile->frst()){
            if(card->getPip() == ACE){
                return true;
            }else{
                return false;
            }
    }
    return false;
}
bool RuleMinusOne::enforce(Pile *pile, card *card){
    if(pile->frst()){
        if(pile->frst()->getPip() - card->getPip() == 1){
            return true;
        }else{
            return false;
        }
    }
    return true;

}

bool RulePlusOne::enforce(Pile *pile, card *card){
    if(pile->frst()){
        if((card->getSuit() == pile->frst()->getSuit()) && card->getPip() - pile->frst()->getPip() == 1){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool RuleDeacresingAlternating::enforce(Pile*pile,card*card){
    bool ok = true;
    //card is the first card to be dragged
    while(ok && card->getOver()){
        ok = (card->getPip() - card->getOver()->getPip() == 1) &&
                (card->getColor() != card->getOver()->getColor());
        card = card->getOver();
    }
    return ok;
};

bool RuleDeacresingSameSuit::enforce(Pile*pile, card* card){
    bool ok = true;
    //card is the first card to be dragged
    while(ok && card->getOver()){
        ok = (card->getPip() - card->getOver()->getPip() == 1) &&
                (card->getSuit() == card->getOver()->getSuit());
        card = card->getOver();
    }
    return ok;
};

card* RuleKingToAce::enforce(Pile*pile, card* cd){
    bool ok = true;
    card* king = NULL;
    cd = pile->last();
    while(cd && cd->getOver()){
      if(cd->getPip() == KING && cd->isfaceup()){
          ok = true;
          king = cd;
          while(ok && cd->getOver()){
              if( (cd->getPip() - cd->getOver()->getPip() == 1) &&
                      (cd->getSuit() == cd->getOver()->getSuit())){
                  cd = cd->getOver();
              }else{
                  ok = false;
              }
          }
      }
      if(ok && cd->getPip() == ACE){
          return king;
      }
      cd = cd->getOver();
    }
    return NULL;

};
