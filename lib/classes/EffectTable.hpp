#pragma once
#include "../AllLib.hpp"
typedef vector<string> Table;

class EffectTable{
private:
    map<int,string> table = {
            {0,"+-------+-----------------------------------+\n"
               "|カード\t|効果\t\t\t\t    |\n"
               "+-------+-----------------------------------+\n"},
            {1,"| 1\t| 与ダメージ1.4倍\t            |\n"},
            {2,"| 2\t| 被ダメージ+10\t\t\t    |\n"},
            {3,"| 3\t| なし\t\t\t\t    |\n"},
            {4,"| 4\t| 与ダメージ+5\t\t\t    |\n"},
            {5,"| 5\t| なし\t\t\t\t    |\n"},
            {6,"| 6\t| なし\t\t\t\t    |\n"},
            {7,"| 7\t| HP15回復\t\t\t    |\n"},
            {8,"| 8\t| なし\t\t\t\t    |\n"},
            {9,"| 9\t| なし\t\t\t\t    |\n"},
            {10,"| 10\t| 被ダメージ-10\t\t\t    |\n"},
            {11,"| 11\t| なし\t\t\t\t    |\n"},
            {12,"| 12\t| 自分の手札を一枚ランダムに捨てる  |\n"},
            {13,"| 13\t| 相手の手札を一枚ランダムに捨てる  |\n"},
            {14,"+-------+-----------------------------------+\n"},
    };
    bool isEffect(int eff_num){
        //effectのlist
        vector<int>eff_list = {1,2,4,7,10,12,13};
        // find関数を使用して数字を検索
        auto it = std::find(eff_list.begin(), eff_list.end(),eff_num);
        // 数字が見つかったかを確認
        if (it != eff_list.end()) {
            return true;//eff_numはエフェクト
        } else {
            return false;//eff_numはエフェクトではない
        }
    }
    Table createEffTable(Hand hands,string target){
        UniqueHand unique_hands;
        //handの重複をなくす
        for (int h:hands[target]) {
            unique_hands[target].insert(h);
        }
        vector<string>new_table;
        new_table.push_back(table[0]);
        //手がeffectを持ってたらtableに加える
        for (int eff_num:unique_hands[target]) {
            if(isEffect(eff_num)){
                new_table.push_back(table[eff_num]);
            }
        }
        new_table.push_back(table[table.size()-1]);
        return new_table;
    }
public:
    EffectTable(){};
    void showTable(Hand hands,string target){
        Table new_table = createEffTable(hands,target);
        for (string record:new_table) {
            cout << record;
        }
    }
    Table getTable(Hand hands,string target){
        return createEffTable(hands,target);
    }
};