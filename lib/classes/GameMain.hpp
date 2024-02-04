#pragma once
#include "../AllLib.hpp"

class GameMain{
private:
    Status S;
    Plot plot_data={
            {"x",{}},
            {"y_Human",{}},
            {"y_AI",{}}
    };
public:
    GameMain(){
        plot_data["x"].push_back(S.tern);
        plot_data["y_Human"].push_back(S.hps["Human"]);
        plot_data["y_AI"].push_back(S.hps["AI"]);
        do {
            S.tern++;
            ternLoop();
            plot_data["x"].push_back(S.tern);
            plot_data["y_Human"].push_back(S.hps["Human"]);
            plot_data["y_AI"].push_back(S.hps["AI"]);

            if (S.result == "WIN" ||S.result == "LOSE"||S.result == "DRAW"){
                S.tern = 0;
                S.hps["Human"] = 100;
                S.hps["AI"] = 100;
            }
        }while(S.is_continue);
    }
    void ternLoop(){
        S.hands = {};
        S.dmgs["Human"]=0;
        S.dmgs["AI"]=0;
        Draw D(S);
        S = D.getStatus();
        Effect E(S);
        S = E.getStatus();
        Attack A(S);
        S = A.getStatus();
        Judge J(S);
        S = J.getStatus();
    }
    Plot getPlotData(){return plot_data;}
    Status getStatus(){return S;}
};
