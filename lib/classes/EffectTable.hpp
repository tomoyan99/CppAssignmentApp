#pragma once
#include "../AllLib.hpp"
typedef vector<string> Table;

class EffectTable{
private:
    map<int,string> table = {
            {0,"+-------+-----------------------------------+\n"
               "|�J�[�h\t|����\t\t\t\t    |\n"
               "+-------+-----------------------------------+\n"},
            {1,"| 1\t| �^�_���[�W1.4�{\t            |\n"},
            {2,"| 2\t| ��_���[�W+10\t\t\t    |\n"},
            {3,"| 3\t| �Ȃ�\t\t\t\t    |\n"},
            {4,"| 4\t| �^�_���[�W+5\t\t\t    |\n"},
            {5,"| 5\t| �Ȃ�\t\t\t\t    |\n"},
            {6,"| 6\t| �Ȃ�\t\t\t\t    |\n"},
            {7,"| 7\t| HP15��\t\t\t    |\n"},
            {8,"| 8\t| �Ȃ�\t\t\t\t    |\n"},
            {9,"| 9\t| �Ȃ�\t\t\t\t    |\n"},
            {10,"| 10\t| ��_���[�W-10\t\t\t    |\n"},
            {11,"| 11\t| �Ȃ�\t\t\t\t    |\n"},
            {12,"| 12\t| �����̎�D���ꖇ�����_���Ɏ̂Ă�  |\n"},
            {13,"| 13\t| ����̎�D���ꖇ�����_���Ɏ̂Ă�  |\n"},
            {14,"+-------+-----------------------------------+\n"},
    };
    bool isEffect(int eff_num){
        //effect��list
        vector<int>eff_list = {1,2,4,7,10,12,13};
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
        //�肪effect�������Ă���table�ɉ�����
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