//
// Created by neeti on 11/6/2018.
//

#include "deck.h"
#include <string>
#include <vector>
#include <ctime>



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

  if (Deck::size() >=2) {
      for (int i = 52; i > 0; i--) {
          int s1, s2;
          randNumber(s1, s2);
          Card temp = myCards[s1];
          myCards[s1] = myCards[s2];
          myCards[s2] = temp;
      }
  }

}

void Deck::randNumber(int &s1,int &s2){
    int numCards = size();
    srand(time(NULL) + s1 + s2);
    s1 = (rand() % numCards);
    s2 = (rand() % numCards);
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

