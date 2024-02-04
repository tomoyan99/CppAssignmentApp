#pragma once
#include "../AllLib.hpp"

bool isEffect(int eff_num){
    //effectのlist
    vector<int>eff_list = {1,2,4,7,8,9,10};
    // find関数を使用して数字を検索
    auto it = std::find(eff_list.begin(), eff_list.end(),eff_num);
    // 数字が見つかったかを確認
    if (it != eff_list.end()) {
        return true;//eff_numはエフェクト
    } else {
        return false;//eff_numはエフェクトではない
    }
}
//手札内の効果持ちの個数を計測
int countEffect(Cards h){
    int count = 0;
    for (int n:h) {
        if (isEffect(n)){count++;}
    }
    return count;
}

bool AI(Cards hand){
    int sum_hand = sumMultiset(hand);
    int cout_eff = countEffect(hand);
    int point = 0;
    int distance = 21 - sum_hand;//出目総和と21との距離。21より大きければマイナス
    //距離が+10より大きかったら確定ドロー
    if(distance >= 10){
        return true;
    }
    //距離が+10以内なら、距離とエフェクトカードの枚数の確率で決定
    if(distance < 10 && distance > 0){
        point += distance*10;//距離1~9に10を掛ける(遠いほど確率高)
        point -= cout_eff*8;//枚数が多いほど確率低
        if(point <= 0){
            return false;
        }else{
            return (rand()%100+1 <= point)?true:false;
        }
    }
    //距離が0(21)なら引かない
    if(distance == 0){
        return false;
    }
    //例外があったら
    throw 1;
}