#pragma once
#include "../AllLib.hpp"
class Attack{
private:
    Damage damages;
    HP hps;
public:
    Attack(HP h,Damage d){
        damages = d;
        hps = h;
    }
    HP getHps(){return hps;}
};
