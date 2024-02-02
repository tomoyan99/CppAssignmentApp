#pragma once
#include <string>
using namespace std;

class Unchi{
private:
    string text;
public:
    Unchi(string t){
        text = t;
        text+="uuuuuuuuuuunchi";
    }
    string getText(){return text;}
};