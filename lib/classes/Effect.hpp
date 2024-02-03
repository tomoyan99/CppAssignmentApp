#pragma once
#include "../AllLib.hpp"
class Effect{
private:
    Hand hands;
    Damage damages;
public:
    Effect(Hand h){
        hands = h;
    }
    Damage getDamages(){return damages;}
};