#pragma once
#include "../AllLib.hpp"


/*
 * �^�C�g����ʂƂ��i����
 * */
class Title{
    Table title_H ={
            "##  ##",
            "##  ##",
            "######",
            "##  ##",
            "##  ##",
    };
    Table title_I ={
            "######",
            "  ##  ",
            "  ##  ",
            "  ##  ",
            "######",
    };
    Table title_G ={
            "######",
            "##    ",
            "##  ##",
            "##  ##",
            "######",
    };

    Table title_J ={
            "######",
            "  ## ",
            "  ##",
            "  ##",
            "### ",
    };

    Table title_A ={
            "  ##  ",
            "##  ##",
            "##  ##",
            "######",
            "##  ##",
    };

    Table title_C ={
            "######",
            "##    ",
            "##    ",
            "##    ",
            "######",
    };

    Table title_K ={
            "##  ##",
            "## ## ",
            "####  ",
            "## ## ",
            "##  ##",
    };
public:
    //�R���X�g���N�^
    Title(){
        system("cls");
        /*
         * �J���[�}�j�s�����[�^
         * */
        Color cyan(36);
        Color yellow(33);
        Color reset(39);

        pair<int,int>start_H = {38,12};

        cout << yellow;

        /*�^�C�g���\����*/
        showAnywhereTxt(title_H,start_H.first+7*0,start_H.second);
        showAnywhereTxt(title_I,start_H.first+7*1,start_H.second);
        showAnywhereTxt(title_G,start_H.first+7*2,start_H.second);
        showAnywhereTxt(title_H,start_H.first+7*3,start_H.second);

        showAnywhereTxt(title_J,start_H.first+7*5,start_H.second);
        showAnywhereTxt(title_A,start_H.first+7*6,start_H.second);
        showAnywhereTxt(title_C,start_H.first+7*7,start_H.second);
        showAnywhereTxt(title_K,start_H.first+7*8,start_H.second);

        cout << reset;
        Sleep(2000);

        /*Static��Data���Ăяo��*/
        StaticData S;

        system("cls");
        /*�T�v*/
        cout << cyan << "[�T�v]" << reset << endl;
        showAnywhereTxt(S.explanation,1,2);
        pause("[�X�y�[�X�L�[�������Ď���]   ��Next:���[��");

        /*���[��*/
        for (int i = 0; i < S.rule.size(); ++i) {
            system("cls");
        cout << cyan << "[���[��("+ to_string(i+1)+"/5)]" << reset << endl;
            showAnywhereTxt(S.rule[i],1,2);
            if(i<S.rule.size()-1){
                pause("[�X�y�[�X�L�[�������Ď���]");
            }else{
                pause("[�X�y�[�X�L�[�������ăQ�[�����J�n]");
            }
        }
    }
};