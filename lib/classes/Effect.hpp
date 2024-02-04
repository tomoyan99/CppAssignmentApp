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
        //effectのlist
        vector<int>eff_list = {1,2,4,7,8,9};
        // find関数を使用して数字を検索
        auto it = std::find(eff_list.begin(), eff_list.end(),eff_num);
        // 数字が見つかったかを確認
        if (it != eff_list.end()) {
            return true;//eff_numはエフェクト
        } else {
            return false;//eff_numはエフェクトではない
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

    //攻撃力1.4倍
    Damage effectOne(Damage dmg,string me,string you,MyView MV){
        dmg[me]*=1.4;
        return dmg;
    }
    //攻撃力-10
    Damage effectTwo(Damage dmg,string me,string you,MyView MV){
        dmg[me]-=10;
        return dmg;
    }
    //攻撃力+10
    Damage effectFour(Damage dmg,string me,string you,MyView MV){
        dmg[me]+=10;
        return dmg;
    }
    //攻撃力0.8倍
    Damage effectFive(Damage dmg,string me,string you,MyView MV){
        dmg[me] *= 0.8;
        return dmg;
    }
    //HPを15回復
    HP effectSeven(HP hps,string me,string you,MyView MV){
        if (hps[me]+15 < 100){
            hps[me]+=15;
        }else if (hps[me]+15 >= 100){
            hps[me] = 100;
            MV.logPause("しかしHPが満タンだったので回復しなかった！ ");
        }
        return hps;
    }
    //me(自分)の手札をランダムで一枚捨てる
    void effectEight(Hand& hands,string me,string you,MyView MV){
        int me_hand_size = hands[me].size();
        // multisetからランダムに要素を選ぶ
        if (me_hand_size > 0) {
            int r;
            r = rand() % me_hand_size;
            auto it = next(hands[me].begin(), r);
            int rand_elem = *it;
            auto range = hands[me].equal_range(rand_elem);
            auto it2 = hands[me].erase(range.first);
            MV.logPause(to_string(rand_elem)+"のカードが破棄されました！ ");
        }else{
            MV.logPause("しかし、"+pn[me]+"には捨てられるカードが残っていない！ ");
        }
    }
    //you(相手)の手札をランダムで1枚捨てる
    void effectNine(Hand& hands,string me,string you,MyView MV){
        int me_hand_size = hands[you].size();
        // multisetからランダムに要素を選ぶ
        if (me_hand_size > 0) {
            int r = rand() % me_hand_size;
            auto it = next(hands[you].begin(), r);
            int rand_elem = *it;
            auto range = hands[you].equal_range(rand_elem);
            auto it2 = hands[you].erase(range.first);
            MV.logPause(to_string(rand_elem)+"のカードが破棄されました！ ");
        }else{
            MV.logPause("しかし、"+pn[you]+"には捨てられるカードが残っていない！ ");
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
        MyView MV("エフェクトフェイズ",S);
        bool cond = rand()%2 == 0;
        string which_first = (cond)?"Human":"AI";//先行決める(0がプレイヤー,1がAI)
        string which_second = (!cond)?"Human":"AI";//後攻決める(0がプレイヤー,1がAI)

        //先行からスタート
        for (int i = 0; i < 2; ++i) {
            MV.logClear();
            if(i==0){MV.logPause("先行は"+pn[which_first]+"からです ");}
            if(i==1){MV.logPause("後攻は"+pn[which_first]+"からです ");}
            for (int n :S.hands[which_first]) {
                if (isEffect(n)){
                    switch (n) {
                        case 1:
                            mf[which_first].a++;
                            MV.logPause("カード1の効果で"+pn[which_first]+"の攻撃力1.4倍! ");
                            S.dmgs = effectOne(S.dmgs,which_first,which_second,MV);
                            break;
                        case 2:
                            mf[which_first].d++;
                            MV.logPause("カード2の効果で"+pn[which_first]+"の攻撃力-10! ");
                            S.dmgs = effectTwo(S.dmgs,which_first,which_second,MV);
                            break;
                        case 4:
                            mf[which_first].c++;
                            MV.logPause("カード4の効果で"+pn[which_first]+"の攻撃力+10! ");
                            S.dmgs = effectFour(S.dmgs,which_first,which_second,MV);
                            break;
                        case 5:
                            mf[which_first].b++;
                            MV.logPause("カード5の効果で"+pn[which_first]+"の攻撃力0.8倍! ");
                            S.dmgs =effectFive(S.dmgs,which_first,which_second,MV);
                            break;
                        case 7:
                            MV.logPause("カード7の効果で"+pn[which_first]+"のHPが15回復! ");
                            S.hps = effectSeven(S.hps,which_first,which_second,MV);
                            break;
                        case 8:
                            MV.logPause("カード8の効果で"+pn[which_first]+"の手札を一枚破棄! ");
                            effectEight(S.hands,which_first,which_second,MV);
                            Sleep(300);
                            break;
                        case 9:
                            MV.logPause("カード9の効果で"+pn[which_second]+"の手札を1枚破棄! ");
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

                    MV.reloadData("エフェクトフェイズ",S);
                    MV.render();
                }
            }
            swap(which_first,which_second);//先行後攻入れ替え
        }
    }
    Status getStatus(){return S;}
};