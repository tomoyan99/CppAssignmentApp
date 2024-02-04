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
        //�m�[�R��
        if(S.hps["Human"] > 0 && S.hps["AI"] > 0){
            S.result = result_list[0];
        };
        //�h���[
        if(S.hps["Human"] == 0 && S.hps["AI"] == 0){
            S.result = result_list[3];
        };
        //����
        if(S.hps["Human"] == 0 && S.hps["AI"] > 0){
            S.result = result_list[2];
        };
        //����
        if(S.hps["Human"] > 0 && S.hps["AI"] == 0){
            S.result = result_list[1];
        };

        MyView MV("�W���b�W�t�F�C�Y",S);
        if (S.result == "NO_CONTEST"){
            MV.addLog(S.result+"!!");
            Sleep(500);
            MV.logPause("���̃^�[���Ɉڂ�܂� ");
            return;
        }
        if (S.result == "WIN" || S.result == "LOSE"){
            MV.addLog("YOU "+S.result+"!!");
            Sleep(500);
            S.is_continue = MV.logConfirm("�R���e�B�j���[���܂����H ");
            return;
        }
        if (S.result == "DRAW"){
            MV.addLog(S.result+"!!");
            Sleep(500);
            S.is_continue = MV.logConfirm("�R���e�B�j���[���܂����H ");
            return;
        }
    }
    Status getStatus(){return S;}
};