#ifndef RULE_H
#define RULE_H
class Pile;
class card;
#include <QList>

class Rule
{
public:
     virtual bool enforce(Pile* pile, card* card)=0;
};

class RuleAlternateColors:public Rule{
    bool enforce(Pile* pile, card* card);
};
class RuleMinusOne:public Rule{
    bool enforce(Pile* pile, card* card);
};
class RuleDeacresingAlternating:public Rule{
    bool enforce(Pile* pile, card* card);
};
class RulePlusOne:public Rule{
    bool enforce(Pile* pile, card* card);
};
class RuleIsAce:public Rule{
    bool enforce(Pile* pile, card* card);
};
class RuleMaxCards{
public:
    bool enforce(QList<Pile*>* piles, card* card);
};

class RuleDeacresingSameSuit:public Rule{
public:
    bool enforce(Pile* pile, card* card);
};
class RuleKingToAce{
public:
    card* enforce(Pile* pile, card* card);
};

class RuleSameSuit:public Rule{
public:
    bool enforce(Pile* pile, card* card);
};
class RuleJustKing:public Rule{
public:
    bool enforce(Pile* pile, card* card);
};
#endif // RULE_H
