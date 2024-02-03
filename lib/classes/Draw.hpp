#pragma once
#include "../AllLib.hpp"
class Draw{
private:
    Hand hands;
    Card *C;
public:
    Draw(){
        C = new Card();
        for (int i = 0; i < 3; ++i) {
            hands["Human"].insert(C->draw());
            hands["AI"].insert(C->draw());
        }
        phase();
    }
    void phase(){
//        View view("[ドローフェイズ]",);
    }
    Hand getHands(){return hands;}
};