#pragma once
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;
void pause(const string& prompt ="[�X�y�[�X�L�[�������Đi��]",const char& key = ' '){
    cout << prompt;
    //�ҋ@
    while (_getch() != key);
    return;
}

bool confirm(string prompt){
    vector<char>keys = {'y','Y','n','N'};
    cout << prompt;
    char yn = _getch();
    auto p = find(keys.begin(), keys.end(),yn);
    while(p == keys.end()){
        yn = _getch();
        p = find(keys.begin(), keys.end(),yn);
    }
    if(yn == 'y' ||yn == 'Y'){
        return true;
    }else{
        return false;
    }
}