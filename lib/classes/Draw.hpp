#pragma once
#include "../AllLib.hpp"
class Draw{
private:
    Status S;
    Card *C;
public:
    Draw(Status s){
        S = s;
        C = new Card();
        for (int i = 0; i < 3; ++i) {
            S.hands["Human"].insert(C->draw());
            S.hands["AI"].insert(C->draw());
        }
        phase();
    }
    void phase(){
        pair<bool,bool> checkDraw={true,true};
        pair<bool,bool> isDraw;
        pair<int,int> sumHands = {sumMultiset(S.hands["Human"]),sumMultiset(S.hands["AI"])};
        S.dmgs["Human"]=sumHands.first;
        S.dmgs["AI"]=sumHands.second;
        MyView MV("ドローフェイズ",S,true);
        do {
            sumHands = {sumMultiset(S.hands["Human"]),sumMultiset(S.hands["AI"])};
            if (sumHands.first > 21){
                checkDraw.first = false;
                MV.logPause("[Player]の手札総和が21を超えているためドロー出来ません");
            }
            if (sumHands.second > 21){
                checkDraw.second = false;
            }
            if (checkDraw.first){
                isDraw.first = MV.logConfirm("追加でカードをドローしますか？");
                if(isDraw.first){
                    int d = C->draw();
                    S.hands["Human"].insert(d);
                    S.dmgs["Human"]+=d;
                    MV.logPause("[Player]はドローを選択し["+ to_string(d)+"]を獲得しました");
                    MV.reloadData("ドローフェイズ",S,true);
                    MV.render();
                }else{
                    checkDraw.first = false;
                }
            }
            if (checkDraw.second){
                isDraw.second = AI(S.hands["AI"]);
                if(isDraw.second){
                    int d = C->draw();
                    S.dmgs["AI"]+=d;
                    S.hands["AI"].insert(d);
                    MV.logPause("[AI]はドローを選択しました");
                }else{
                    checkDraw.second = false;
                }
            }
        }while(checkDraw.first || checkDraw.second );//どっちかがtrueなら継続
        MV.logPause("双方ドローが選択されませんでした。次のフェイズへ進みます");
    }
    Status getStatus(){return S;}
};