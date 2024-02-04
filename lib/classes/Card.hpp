#pragma once
#include "../AllLib.hpp"
class Card{
private:
    queue<int>deck;
public:
    Card(){
        //����vector
        vector<int>deck_temp;
        for (int i = 0; i < 4; ++i) {
            for (int j = 1; j <= 10; ++j) {
                deck_temp.push_back(j);
            }
        }
        //vector���V���b�t��
        random_shuffle(deck_temp.begin(),deck_temp.end());
        for (int card:deck_temp) {
            deck.push(card);
        }
    }
    //�L���[�̐擪���琔���������Ă���
    int draw(){
        int hand = deck.front();
        deck.pop();
        return hand;
    }
};