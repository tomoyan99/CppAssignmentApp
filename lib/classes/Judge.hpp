#pragma once
#include "../AllLib.hpp"


class Judge{
private:
    Status S;
public:
    Judge(Status s){
        S = s;
        phase();
    }
    void phase(){
        vector<string> result_list = {"NO_CONTEST","WIN","LOSE","DRAW"};
        //ノーコン
        if(S.hps["Human"] > 0 && S.hps["AI"] > 0){
            S.result = result_list[0];
        };
        //ドロー
        if(S.hps["Human"] == 0 && S.hps["AI"] == 0){
            S.result = result_list[3];
        };
        //負け
        if(S.hps["Human"] == 0 && S.hps["AI"] > 0){
            S.result = result_list[2];
        };
        //勝ち
        if(S.hps["Human"] > 0 && S.hps["AI"] == 0){
            S.result = result_list[1];
        };

        MyView MV("ジャッジフェイズ",S);
        if (S.result == "NO_CONTEST"){
            MV.addLog(S.result+"!!");
            Sleep(500);
            MV.logPause("次のターンに移ります ");
            return;
        }
        if (S.result == "WIN" || S.result == "LOSE"){
            MV.addLog("YOU "+S.result+"!!");
            Sleep(500);
            S.is_continue = MV.logConfirm("コンティニューしますか？ ");
            return;
        }
        if (S.result == "DRAW"){
            MV.addLog(S.result+"!!");
            Sleep(500);
            S.is_continue = MV.logConfirm("コンティニューしますか？ ");
            return;
        }
    }
    Status getStatus(){return S;}
};