#include "../lib/AllLib.hpp"

using namespace std;

int main(void) {
    Status s;
    s.hands = {
            {"Human",{1,2,3,4,4,4}},
            {"AI",{3,4,4,6}}
    };
    Effect E(s);
    pause("");
    return 0;
}