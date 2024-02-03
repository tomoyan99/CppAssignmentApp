#pragma once
#include "../AllLib.hpp"
class GameMain{
private:
    HP hps={
            {"Human",100},
            {"AI",100}
    };
    Result result={"NO_CONTEST","WIN","LOSE","DRAW"};
public:
    GameMain(){
        tern();
    }
    void tern(){
        Draw D;
        Hand hands = D.getHands();
        Effect E(hands);
        Damage damages = E.getDamages();
        Attack A(hps,damages);
        hps = A.getHps();
        Judge J(hps);
        result = J.getResult();
    }
};
