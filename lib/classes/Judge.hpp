#pragma once
#include "../AllLib.hpp"

class Judge{
private:
    HP hps;
    Result result;
public:
    Judge(HP h){
        hps = h;
    }
    Result getResult(){return result;}
};