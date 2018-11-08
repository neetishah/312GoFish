#include <iostream>
#include "deck.h"
#include "card.h"

using namespace std;


int main() {
    Deck d;
    d.shuffle();
    while (d.size()) {
        cout << d.dealCard() << endl;
    }

    return 0;
}