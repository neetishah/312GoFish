#include "card.h"
#include <string>


//#define CARD_H
//#ifdef CARD_H
using namespace std;

Card::Card(){                                     // default, ace of spades
    myRank= 'A';
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const{                   // return string version e.g. Ac 4h Js
    string rank = rankString(myRank);
    string suit = suitString(mySuit);
    string together = rank + suit;
    return together;
}


bool Card::sameSuitAs(const Card& c) const{          // true if suit same as c
    if (mySuit == c.mySuit){
        return true;
    }

    else return false;

}

int  Card::getRank() const{                         // return rank, 1..13
    return myRank;

}

string Card::suitString(Suit s) const {         // return "s", "h",...
    string suit;
    if (s == 0){
        suit = "s";
        return suit;
    }
    if (s == 1){
        suit = "h";
        return suit;
    }
    if (s == 2){
        suit = "d";
        return suit;
    }
    if (s == 3){
        suit = "c";
        return suit;
    }
}

string Card::rankString(int r) const {           // return "A", "2", ..."Q"
    string rank;
    if (r == 11){
        rank = "J";
    }
    else if (r == 12){
        rank = "Q";
    }
    else if (r == 13){
        rank = "K";
    }
    else if (r == 1){
        rank = "A";
    }

    else rank= to_string(static_cast<long long>(r));

    return rank;

}


bool Card::operator == (const Card& rhs) const{
    if ((this -> myRank == rhs.myRank) && (this->mySuit == rhs.mySuit)){
        return true;
    }
    else return false;
}

bool Card::operator != (const Card& rhs) const{
    if ((this -> myRank != rhs.myRank) | (this->mySuit != rhs.mySuit)){
        return true;
    }
    else return false;
}

ostream& operator << (ostream& out, const Card& c) {
    out << c.toString();
    return out;
}
