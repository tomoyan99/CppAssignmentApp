#pragma once
#include "../AllLib.hpp"
class EffectTable{
private:
    map<int,string> table = {
            {0,"+-------+-----------------------------------+"},
            {1,"|�J�[�h | ����                              |"},
            {2,"+-------+-----------------------------------+"},
            {3,"| 1     | �U����1.4�{                       |"},
            {4,"| 2     | �U����-10                         |"},
            {5,"| 3     | �Ȃ�                              |"},
            {6,"| 4     | �U����+10                         |"},
            {7,"| 5     | �U����0.8�{                       |"},
            {8,"| 6     | �Ȃ�                              |"},
            {9,"| 7     | HP15��                          |"},
            {10,"| 8     | �����̎�D���ꖇ�����_���Ɏ̂Ă�  |"},
            {11,"| 9     | ����̎�D���ꖇ�����_���Ɏ̂Ă�  |"},
            {12,"| 10    | �Ȃ�                              |"},
            {13,"+-------+-----------------------------------+"},
            };
    int table_end_index = table.size()-1;
    int bias = 2;
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
    Table createEffTable(Hand hands,string target){
        UniqueHand unique_hands;
        //hand�̏d�����Ȃ���
        for (int h:hands[target]) {
            unique_hands[target].insert(h);
        }
        vector<string>new_table;
        new_table.push_back(table[0]);
        new_table.push_back(table[1]);
        new_table.push_back(table[2]);
        UniqueHand effect_hands;
        //�肪effect�������Ă���table�ɉ�����
        for (int eff_num:unique_hands[target]) {
            if(isEffect(eff_num)){
                effect_hands[target].insert(eff_num);
                new_table.push_back(table[eff_num+bias]);
            }
        }
        if(effect_hands[target].size() == 0){
            new_table.push_back({"|       | �Ȃ�                              |"});
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
        new_table.push_back({"| �� [AI]�̎�D�͎��̃t�F�C�Y�ŊJ������܂�  |"});
        new_table.push_back(table[table_end_index]);
        return new_table;
    }
    Table getTable(Hand hands,string target){
        return createEffTable(hands,target);
    }
};