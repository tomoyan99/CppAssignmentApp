#pragma once
#include <iostream>
#include "Number.h"

class MyManipu {
    friend ostream& operator <<(ostream& ros, IOSYSTEMFIRST intmaniac) {
        return intmaniac(ros);
    }
private:
    char ioSystem0[5][5];
    char ioSystem1[5][5];
    char ioSystem2[5][5];
public:
    IOSYSTEMFIRST(char number0[5][5], char number1[5][5], char number2[5][5], string player) {
        NUMBER number;

        number.checkNomber(player[0], number0);
        number.checkNomber(player[1], number1);
        number.checkNomber(player[2], number2);

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                ioSystem0[i][j] = number0[i][j];
                ioSystem1[i][j] = number1[i][j];
                ioSystem2[i][j] = number2[i][j];
            }
        }
    }
private:
    ostream& operator()(ostream& ros) {

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 17; j++) {
                if (j < 5) {
                    ros << ioSystem0[i][j];
                    continue;
                }
                if (j == 5) {
                    ros << " ";
                    continue;
                }
                if (j < 11) {
                    ros << ioSystem1[i][j - 6];
                    continue;
                }
                if (j == 11) {
                    ros << " ";
                    continue;
                }
                if (j < 17) {
                    ros << ioSystem2[i][j - 12];
                    continue;
                }
            }
            ros << "\n";
        }ros << "\n";
        return ros;
    }
};
