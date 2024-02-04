#pragma once
#include "../AllLib.hpp"
class EffectTable{
private:
    map<int,string> table = {
            {0,"+-------+-----------------------------------+"},
            {1,"|カード | 効果                              |"},
            {2,"+-------+-----------------------------------+"},
            {3,"| 1     | 攻撃力1.4倍                       |"},
            {4,"| 2     | 攻撃力-10                         |"},
            {5,"| 3     | なし                              |"},
            {6,"| 4     | 攻撃力+10                         |"},
            {7,"| 5     | 攻撃力0.8倍                       |"},
            {8,"| 6     | なし                              |"},
            {9,"| 7     | HP15回復                          |"},
            {10,"| 8     | 自分の手札を一枚ランダムに捨てる  |"},
            {11,"| 9     | 相手の手札を一枚ランダムに捨てる  |"},
            {12,"| 10    | なし                              |"},
            {13,"+-------+-----------------------------------+"},
            };
    int table_end_index = table.size()-1;
    int bias = 2;
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
    Table createEffTable(Hand hands,string target){
        UniqueHand unique_hands;
        //handの重複をなくす
        for (int h:hands[target]) {
            unique_hands[target].insert(h);
        }
        vector<string>new_table;
        new_table.push_back(table[0]);
        new_table.push_back(table[1]);
        new_table.push_back(table[2]);
        UniqueHand effect_hands;
        //手がeffectを持ってたらtableに加える
        for (int eff_num:unique_hands[target]) {
            if(isEffect(eff_num)){
                effect_hands[target].insert(eff_num);
                new_table.push_back(table[eff_num+bias]);
            }
        }
        if(effect_hands[target].size() == 0){
            new_table.push_back({"|       | なし                              |"});
        }
        new_table.push_back(table[table_end_index]);
        return new_table;
    }
public:
    EffectTable(){};
    void showTable(Hand hands,string target){
        Table new_table = createEffTable(hands,target);
        for (string record:new_table) {
            cout << record << endl;
        }
    }
    Table getRawTable(){
        vector<string>new_table;
        for (int i = 0; i < table.size(); ++i) {
          new_table.push_back(table[i]);
        }
        return new_table;
    }
    Table getDummyTable(){
        vector<string>new_table;
        new_table.push_back(table[0]);
        new_table.push_back(table[1]);
        new_table.push_back(table[2]);
        new_table.push_back({"| ※ [AI]の手札は次のフェイズで開示されます  |"});
        new_table.push_back(table[table_end_index]);
        return new_table;
    }
    Table getTable(Hand hands,string target){
        return createEffTable(hands,target);
    }
};