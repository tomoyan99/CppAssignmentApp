#pragma once
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;
void pause(const string& prompt ="[スペースキーを押して進む]",const char& key = ' '){
    cout << prompt;
    //待機
    while (_getch() != key);
    return;
}