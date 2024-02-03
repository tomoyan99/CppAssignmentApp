#pragma once
#include "../AllLib.hpp"
class GameMain{
private:
    Hand hands={
            {"Human",{}},
            {"AI",{}}
    };
    Damage dameges = {
            {"Human",{}},
            {"AI",{}}
    };
    HP hps={
            {"Human",{}},
            {"AI",{}}
    };


public:
    GameMain(){
        tern();
    }
    void tern(){
        Draw D(hands);
        hands = D.getHands();
        Effect E(hands);
        damages = E.getDameges();
        Attack A(hps,damages);
        hps = A.getHps();

    }
};
