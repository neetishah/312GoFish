//
// Created by neeti on 11/6/2018.
//

#include "deck.h"
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>



Deck::Deck() {                                                             // pristine, sorted deck
    int j = 0;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            Card c(rank, (Card::Suit) suit);
            myCards[j] = c;
            j++;
        }
    }
    myIndex = 0;
}

void Deck::shuffle() {                                                          // shuffle the cards in the current deck

    int numCards = size();
    int s1;
//    int srandSeed = time(NULL) + s1;
    srand(5);
//    srand(0);
    if (Deck::size() >= 2) {
        for (int i = 200; i > 0; i--) {
            long index1 = (rand() % numCards) ;
            long index2 = (rand() % numCards) ;
            Card temp = myCards[index1];
            myCards[index1] = myCards[index2];
            myCards[index2] = temp;

        }


    }
}

Card Deck::dealCard() {   // get a card; after 52 are dealt, fail
 //   int index = Deck::size()-1;
    Card top= myCards[myIndex];
    if (size()!=0){
        myIndex++;
        return top;
    }
}

int  Deck::size() const { // # cards left in the deck
    return (52-myIndex);
}

