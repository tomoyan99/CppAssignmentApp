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