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
        MyView MV("�A�^�b�N�t�F�C�Y",S);
        pair<int,int> sumHands = {sumMultiset(S.hands["Human"]),sumMultiset(S.hands["AI"])};

        pair<int,int> count = {0,0};
        if(sumHands.first > 21 || sumHands.second > 21){
            if(sumHands.first > 21){
                MV.logPause("��D�̑��a��21�𒴂��Ă��邽��[Player]�͍U���ł��Ȃ�!! ");
                count.first++;
            }
            if(sumHands.second > 21) {
                MV.logPause("��D�̑��a��21�𒴂��Ă��邽��[AI]�͍U���ł��Ȃ�!! ");
                count.second++;
            }
            if(count.first+count.second == 2){
                MV.logPause("�ǂ�����U���ł����A�����͂��a���ƂȂ����c�c �����̃^�[���ɑ���");
                return;
            }
        }
        if(count.first == 0){
            MV.logClear();
            if(sumHands.first == 21){
                MV.logPause("\x1b[37m�m�E�`�����X�����I�I\x1b[39m ");
                MV.logPause("�m�E�`�����X�E�E�E����͏o�ڂ�21�̎҂݂̂ɗ^������`�����X ");
                MV.logPause("������΃_���[�W100�|�C���g��悹�I ");
                MV.logPause("���ʂ́E�E�E�E�E�E ");
                Sleep(3000);
                MV.logClear();
                Sleep(500);
                if(calcKillCh(S.hands["Human"])){
                    MV.addLog("\x1b[31m�m                 �E\x1b[39m");
                    Sleep(500);
                    MV.addLog("�_���[�W��100�|�C���g����悹����܂� ");
                    S.dmgs["Human"]+=100;
                    MV.reloadData("�A�^�b�N�t�F�C�Y",S);
                    MV.render();
                }else{
                    MV.addLog("�c�O�E�E�E�m�E�Ȃ炸 ");
                }
            }
            MV.logPause("[Player]�̍U���I�I ");
            MV.logPause("[AI]��"+ to_string(S.dmgs["Human"])+"�_���[�W!! ");
            if (S.hps["AI"]-S.dmgs["Human"]>0){
                S.hps["AI"]-=S.dmgs["Human"];
            }else{
                S.hps["AI"] = 0;
            }
            MV.reloadData("�A�^�b�N�t�F�C�Y",S);
            MV.render();

        }
        if(count.second == 0){
            MV.logClear();
            if(sumHands.second == 21){
                MV.logPause("\x1b[37m�m�E�`�����X�����I�I\x1b[39m ");
                MV.logPause("���ʂ́E�E�E�E�E�E ");
                Sleep(1000);
                if(calcKillCh(S.hands["Human"])){
                    MV.addLog("\x1b[31m�m                 �E\x1b[39m");
                    Sleep(500);
                    MV.addLog("�_���[�W��100�|�C���g����悹����܂� ");
                    S.dmgs["AI"]+=100;
                    MV.reloadData("�A�^�b�N�t�F�C�Y",S);
                    MV.render();
                }else{
                    MV.addLog("�c�O�E�E�E�m�E�Ȃ炸 ");
                }
            }
            MV.logPause("[AI]�̍U���I�I ");
            MV.logPause("[Player]��"+ to_string(S.dmgs["AI"])+"�_���[�W!! ");
            if (S.hps["Human"]-S.dmgs["AI"]>0){
                S.hps["Human"]-=S.dmgs["AI"];
            }else{
                S.hps["Human"] = 0;
            }
            MV.reloadData("�A�^�b�N�t�F�C�Y",S);
            MV.render();
        }
    }
    Status getStatus(){return S;}
};
