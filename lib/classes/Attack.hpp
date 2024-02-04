#pragma once
#include "../AllLib.hpp"
class Attack{
private:
    Status S;
    bool calcKillCh(Cards c){
        int chance = 0;
        chance = (int)(1.0 - (c.size() - 2)*0.2)*100;

        return ((rand()%100+1)<=chance);
    }
public:
    Attack(Status s){
        S = s;
        phase();
    }
    void phase(){
        MyView MV("アタックフェイズ",S);
        pair<int,int> sumHands = {sumMultiset(S.hands["Human"]),sumMultiset(S.hands["AI"])};

        pair<int,int> count = {0,0};
        if(sumHands.first > 21 || sumHands.second > 21){
            if(sumHands.first > 21){
                MV.logPause("手札の総和が21を超えているため[Player]は攻撃できない!! ");
                count.first++;
            }
            if(sumHands.second > 21) {
                MV.logPause("手札の総和が21を超えているため[AI]は攻撃できない!! ");
                count.second++;
            }
            if(count.first+count.second == 2){
                MV.logPause("どちらも攻撃できず、勝負はお預けとなった…… →次のターンに続く");
                return;
            }
        }
        if(count.first == 0){
            MV.logClear();
            if(sumHands.first == 21){
                MV.logPause("\x1b[37m確殺チャンス発生！！\x1b[39m ");
                MV.logPause("確殺チャンス・・・それは出目が21の者のみに与えられるチャンス ");
                MV.logPause("当たればダメージ100ポイント上乗せ！ ");
                MV.logPause("結果は・・・・・・ ");
                Sleep(3000);
                MV.logClear();
                Sleep(500);
                if(calcKillCh(S.hands["Human"])){
                    MV.addLog("\x1b[31m確                 殺\x1b[39m");
                    Sleep(500);
                    MV.addLog("ダメージに100ポイントが上乗せされます ");
                    S.dmgs["Human"]+=100;
                    MV.reloadData("アタックフェイズ",S);
                    MV.render();
                }else{
                    MV.addLog("残念・・・確殺ならず ");
                }
            }
            MV.logPause("[Player]の攻撃！！ ");
            MV.logPause("[AI]に"+ to_string(S.dmgs["Human"])+"ダメージ!! ");
            if (S.hps["AI"]-S.dmgs["Human"]>0){
                S.hps["AI"]-=S.dmgs["Human"];
            }else{
                S.hps["AI"] = 0;
            }
            MV.reloadData("アタックフェイズ",S);
            MV.render();

        }
        if(count.second == 0){
            MV.logClear();
            if(sumHands.second == 21){
                MV.logPause("\x1b[37m確殺チャンス発生！！\x1b[39m ");
                MV.logPause("結果は・・・・・・ ");
                Sleep(1000);
                if(calcKillCh(S.hands["Human"])){
                    MV.addLog("\x1b[31m確                 殺\x1b[39m");
                    Sleep(500);
                    MV.addLog("ダメージに100ポイントが上乗せされます ");
                    S.dmgs["AI"]+=100;
                    MV.reloadData("アタックフェイズ",S);
                    MV.render();
                }else{
                    MV.addLog("残念・・・確殺ならず ");
                }
            }
            MV.logPause("[AI]の攻撃！！ ");
            MV.logPause("[Player]に"+ to_string(S.dmgs["AI"])+"ダメージ!! ");
            if (S.hps["Human"]-S.dmgs["AI"]>0){
                S.hps["Human"]-=S.dmgs["AI"];
            }else{
                S.hps["Human"] = 0;
            }
            MV.reloadData("アタックフェイズ",S);
            MV.render();
        }
    }
    Status getStatus(){return S;}
};
