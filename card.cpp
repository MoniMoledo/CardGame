#include "card.h"

card::card(int v, QWidget * parent)
{

}

/*static definitions
 * QIMAge CARD:: faces[53];
 * bool initialized = false
 * Qpoint mousedownoffset
 *
 *
 *
 * initialize(){
 * if(initialized) return;
 * char suit[] = c,d,h,s
 * char pip[]= 123456789abcd
 * int n = 0
 * qstring fname = ":cards/c1.bmp";
 * for s=clubs; s<=spades;s++{
 * fname[8] = suit[s];
 * for p = ACE, p<= KING, p++{
 * fname[9] = pip[p]
 * faces[n++] = QImage(fname)}}
 * faces[n] = QImage("/cards/zCardBack.bmp");
 * */

QImage card::faces[53];
bool card::initialized = false;

void card::Initialize(){
    if(initialized){
        return;
    }
    char suit[] = {'c','d', 'h', 's'};
    char pip[] = {'1','2','3','4','5','6','7','8','9','a','b','c','d'};
    int n =0;
    QString fname = ":cards/c1.bmp";
    for(int s = CLUBS; s<= SPADES; s++){
        fname[8] = suit[s];
        for(int p=ACE; p<=KING; p++){
            fname[9] = pip[p];
            faces[n++] = QImage(fname);
        }
    }
    faces[n] = QImage("/cards/zCardBack.bmp");
}
