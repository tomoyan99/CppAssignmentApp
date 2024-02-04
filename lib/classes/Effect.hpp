#pragma once
#include "../AllLib.hpp"

class Effect{
private:
    Status S;
    struct Flug{
        int a;
        int b;
        int c;
        int d;
        Flug(){
            a = 0;
            b = 0;
            c = 0;
            d = 0;
        }
    };

    map<string,string>pn = {
            {"Human","[Player]"},
            {"AI","[AI]"},
    };
    vector<string>player_list = {"Human","AI"};
    bool isEffect(int eff_num){
        //effect��list
        vector<int>eff_list = {1,2,4,7,8,9};
        // find�֐����g�p���Đ���������
        auto it = std::find(eff_list.begin(), eff_list.end(),eff_num);
        // �������������������m�F
        if (it != eff_list.end()) {
            return true;//eff_num�̓G�t�F�N�g
        } else {
            return false;//eff_num�̓G�t�F�N�g�ł͂Ȃ�
        }
    }
    Damage calcDamage(Status s,map<string,Flug> mf){
        s.dmgs["Human"]= sumMultiset(s.hands["Human"])
                *pow(1.4,mf["Human"].a)
                *pow(0.8,mf["Human"].b)
                +(10*mf["Human"].c)
                +(-10*mf["Human"].d);
        s.dmgs["AI"]= sumMultiset(s.hands["AI"])
                         *pow(1.4,mf["AI"].a)
                         *pow(0.8,mf["AI"].b)
                         +(10*mf["AI"].c)
                         +(-10*mf["AI"].d);
        return s.dmgs;
    }

    //�U����1.4�{
    Damage effectOne(Damage dmg,string me,string you,MyView MV){
        dmg[me]*=1.4;
        return dmg;
    }
    //�U����-10
    Damage effectTwo(Damage dmg,string me,string you,MyView MV){
        dmg[me]-=10;
        return dmg;
    }
    //�U����+10
    Damage effectFour(Damage dmg,string me,string you,MyView MV){
        dmg[me]+=10;
        return dmg;
    }
    //�U����0.8�{
    Damage effectFive(Damage dmg,string me,string you,MyView MV){
        dmg[me] *= 0.8;
        return dmg;
    }
    //HP��15��
    HP effectSeven(HP hps,string me,string you,MyView MV){
        if (hps[me]+15 < 100){
            hps[me]+=15;
        }else if (hps[me]+15 >= 100){
            hps[me] = 100;
            MV.logPause("������HP�����^���������̂ŉ񕜂��Ȃ������I ");
        }
        return hps;
    }
    //me(����)�̎�D�������_���ňꖇ�̂Ă�
    void effectEight(Hand& hands,string me,string you,MyView MV){
        int me_hand_size = hands[me].size();
        // multiset���烉���_���ɗv�f��I��
        if (me_hand_size > 0) {
            int r;
            r = rand() % me_hand_size;
            auto it = next(hands[me].begin(), r);
            int rand_elem = *it;
            auto range = hands[me].equal_range(rand_elem);
            auto it2 = hands[me].erase(range.first);
            MV.logPause(to_string(rand_elem)+"�̃J�[�h���j������܂����I ");
        }else{
            MV.logPause("�������A"+pn[me]+"�ɂ͎̂Ă���J�[�h���c���Ă��Ȃ��I ");
        }
    }
    //you(����)�̎�D�������_����1���̂Ă�
    void effectNine(Hand& hands,string me,string you,MyView MV){
        int me_hand_size = hands[you].size();
        // multiset���烉���_���ɗv�f��I��
        if (me_hand_size > 0) {
            int r = rand() % me_hand_size;
            auto it = next(hands[you].begin(), r);
            int rand_elem = *it;
            auto range = hands[you].equal_range(rand_elem);
            auto it2 = hands[you].erase(range.first);
            MV.logPause(to_string(rand_elem)+"�̃J�[�h���j������܂����I ");
        }else{
            MV.logPause("�������A"+pn[you]+"�ɂ͎̂Ă���J�[�h���c���Ă��Ȃ��I ");
        }
    }

public:
    Effect(Status s){
        S = s;
        phase();
    }
    void phase(){
        map<string,Flug>mf = {
                {"Human",{}},
                {"AI",{}}
        };
        MyView MV("�G�t�F�N�g�t�F�C�Y",S);
        bool cond = rand()%2 == 0;
        string which_first = (cond)?"Human":"AI";//��s���߂�(0���v���C���[,1��AI)
        string which_second = (!cond)?"Human":"AI";//��U���߂�(0���v���C���[,1��AI)

        //��s����X�^�[�g
        for (int i = 0; i < 2; ++i) {
            MV.logClear();
            if(i==0){MV.logPause("��s��"+pn[which_first]+"����ł� ");}
            if(i==1){MV.logPause("��U��"+pn[which_first]+"����ł� ");}
            for (int n :S.hands[which_first]) {
                if (isEffect(n)){
                    switch (n) {
                        case 1:
                            mf[which_first].a++;
                            MV.logPause("�J�[�h1�̌��ʂ�"+pn[which_first]+"�̍U����1.4�{! ");
                            S.dmgs = effectOne(S.dmgs,which_first,which_second,MV);
                            break;
                        case 2:
                            mf[which_first].d++;
                            MV.logPause("�J�[�h2�̌��ʂ�"+pn[which_first]+"�̍U����-10! ");
                            S.dmgs = effectTwo(S.dmgs,which_first,which_second,MV);
                            break;
                        case 4:
                            mf[which_first].c++;
                            MV.logPause("�J�[�h4�̌��ʂ�"+pn[which_first]+"�̍U����+10! ");
                            S.dmgs = effectFour(S.dmgs,which_first,which_second,MV);
                            break;
                        case 5:
                            mf[which_first].b++;
                            MV.logPause("�J�[�h5�̌��ʂ�"+pn[which_first]+"�̍U����0.8�{! ");
                            S.dmgs =effectFive(S.dmgs,which_first,which_second,MV);
                            break;
                        case 7:
                            MV.logPause("�J�[�h7�̌��ʂ�"+pn[which_first]+"��HP��15��! ");
                            S.hps = effectSeven(S.hps,which_first,which_second,MV);
                            break;
                        case 8:
                            MV.logPause("�J�[�h8�̌��ʂ�"+pn[which_first]+"�̎�D���ꖇ�j��! ");
                            effectEight(S.hands,which_first,which_second,MV);
                            Sleep(300);
                            break;
                        case 9:
                            MV.logPause("�J�[�h9�̌��ʂ�"+pn[which_second]+"�̎�D��1���j��! ");
                            effectNine(S.hands,which_first,which_second,MV);
                            Sleep(300);
                            break;
                    }
                    S.dmgs = calcDamage(S,mf);
                    if (S.dmgs[which_first] < 0){
                        S.dmgs[which_first] = 0;
                    }
                    if (S.dmgs[which_second] < 0){
                        S.dmgs[which_second] = 0;
                    }

                    MV.reloadData("�G�t�F�N�g�t�F�C�Y",S);
                    MV.render();
                }
            }
            swap(which_first,which_second);//��s��U����ւ�
        }
    }
    Status getStatus(){return S;}
};