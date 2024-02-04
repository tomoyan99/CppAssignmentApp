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
        MyView MV("�h���[�t�F�C�Y",S,true);
        do {
            sumHands = {sumMultiset(S.hands["Human"]),sumMultiset(S.hands["AI"])};
            if (sumHands.first > 21){
                checkDraw.first = false;
                MV.logPause("[Player]�̎�D���a��21�𒴂��Ă��邽�߃h���[�o���܂���");
            }
            if (sumHands.second > 21){
                checkDraw.second = false;
            }
            if (checkDraw.first){
                isDraw.first = MV.logConfirm("�ǉ��ŃJ�[�h���h���[���܂����H");
                if(isDraw.first){
                    int d = C->draw();
                    S.hands["Human"].insert(d);
                    S.dmgs["Human"]+=d;
                    MV.logPause("[Player]�̓h���[��I����["+ to_string(d)+"]���l�����܂���");
                    MV.reloadData("�h���[�t�F�C�Y",S,true);
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
                    MV.logPause("[AI]�̓h���[��I�����܂���");
                }else{
                    checkDraw.second = false;
                }
            }
        }while(checkDraw.first || checkDraw.second );//�ǂ�������true�Ȃ�p��
        MV.logPause("�o���h���[���I������܂���ł����B���̃t�F�C�Y�֐i�݂܂�");
    }
    Status getStatus(){return S;}
};