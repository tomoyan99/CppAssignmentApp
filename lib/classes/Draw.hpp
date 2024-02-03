#pragma once
#include "../AllLib.hpp"
class Draw{
private:
    Hand tmpHands;
    Card *C;
public:
    Draw(Hand hands){
        tmpHands = hands;
        C = new Card();
        for (int i = 0; i < 3; ++i) {
            hands["Human"][i]=C->draw();
            hands["AI"][i]=C->draw();
        }
        phase();
    }
    void phase(){

    }
    Hand getHands(){return tmpHands;}
};