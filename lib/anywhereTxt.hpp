#pragma once
#include "AllLib.hpp"
void showAnywhereTxt(Table t,int x,int y){
    string first = "\x1b[1;1H\x1b["+ to_string(y)+"B";
    string prefix = "\x1b["+ to_string(x)+"G";
    string suffix = "\x1b[1E";
    cout << first;
    for (string row:t) {
        cout << prefix << row << suffix;
    }
}
string getAnywhereTxt(Table t,int x, int y){
    string first = "\x1b[1;1H\x1b["+ to_string(y)+"B";
    string prefix = "\x1b["+ to_string(x)+"G";
    string anywhere_txt;
    anywhere_txt+=first;
    for (string row:t) {
        anywhere_txt+=prefix+row;
    }
    return anywhere_txt;
}
void showAnywhereTxt(string s,int x,int y){
    string first = "\x1b[1;1H\x1b["+ to_string(y)+"B";
    string prefix = "\x1b["+ to_string(x)+"G";
    string suffix = "\x1b[1E";
    cout << first;
    cout << prefix << s << suffix;
}
string getAnywhereTxt(string s,int x, int y){
    string first = "\x1b[1;1H\x1b["+ to_string(y)+"B";
    string prefix = "\x1b["+ to_string(x)+"G";
    string anywhere_txt;
    anywhere_txt+=first+anywhere_txt+=prefix+s;
    return anywhere_txt;
}
