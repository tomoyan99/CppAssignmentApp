#pragma once
class Calc{
private:
    int a;
    int b;
public:
    Calc(int x,int y){
        a = x;
        b = y;
    }
    int sum(){
        return a+b;
    }
};