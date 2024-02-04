#pragma once
#include "AllLib.hpp"
int sumMultiset(const multiset<int>& ms) {
    int sum = 0;
    for (const auto& element : ms) {
        sum += element;
    }
    return sum;
}
string getPrintArray(multiset<int> vec){
    string str;
    str+="[";
    for (int n:vec) {
        str+=" "+ to_string(n);
    }
    str+=" ]";
    return str;
}