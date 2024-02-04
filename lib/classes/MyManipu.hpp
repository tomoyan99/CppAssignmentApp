#pragma once
#include <bits/stdc++.h>

using namespace std;

// テキストの色を変更するマニピュレータ
class Color {
private:
    //ANSIエスケープコードの色コード31~39?
    int colorCode;
public:
    //カラーコードに合ったインスタンスの生成
    Color(int code) : colorCode(code) {}
    //マニピュレータ本体
    friend ostream& operator<<(ostream& os, Color& manipulator) {
        return os << "\033[" << manipulator.colorCode << "m";
    }
};
