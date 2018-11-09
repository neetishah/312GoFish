// FILE:  player.cpp
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks


using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "deck.h"
#include <algorithm>


Player::Player(){
    myName = "Player";
//    for (int i =0; i<7; i++){
//        myHand[i]= Deck::dealCard();
//    }
//    myBook=0
}


    void Player::addCard(Card c) { //adds a card to the hand
        myHand.push_back(c);
    }

    void Player::bookCards(Card c1, Card c2){
        if (c1.getRank() == c2.getRank()){
            myBook.push_back(c1);
            myBook.push_back(c2);
        }
}

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards that make the pair.

    bool Player::checkHandForBook(Card &c1, Card &c2){

    if ((myHand.size() == (0)) | myHand.size() == (1)) {
        return false;
    }
    else {
        vector<Card>::iterator startPtr = myHand.begin();
        vector<Card>::iterator endPtr = startPtr + (myHand.size()-1);
//        vector<Card>::iterator endPtr = myHand.end();

        for (startPtr = myHand.begin(); startPtr != endPtr + 1; startPtr++) {
            for (vector<Card>::iterator topPtr = startPtr + 1; topPtr != endPtr + 1; topPtr++) {
                if (topPtr->getRank() == startPtr->getRank()) {
                    c1 = *topPtr;
                    c2 = *startPtr;
                    return true;
                }
            }
        }

        return false;
    }

}

    //OPTIONAL
    //comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    bool Player::rankInHand(Card c) const{
        vector<Card>::const_iterator iter = myHand.begin();
        for(iter = myHand.begin(); iter < myHand.end(); iter++){
           if (iter->getRank()== c.getRank()){
               return true;
           }
        }
        return false;

}

    //uses some strategy to choose one card from the player's hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const{
        int s1;
        int numCards = myHand.size();
        int srandSeed = time(NULL) + s1;
        srand(srandSeed);
        s1 = (rand() % numCards);

        return myHand[s1];
}

    //Does the player have the card c in her hand?
    bool Player::cardInHand(Card c) const{
        for (vector<Card>::const_iterator iter = myHand.begin(); iter <= myHand.end(); iter++){
            if (*iter==c){
                return true;
            }
        }

        return false;


}

    //Remove the card c from the hand and return it to the caller
    Card Player::removeCardFromHand(Card c){
        int cnt=0;
        for (vector<Card>::const_iterator iter = myHand.begin(); iter <= myHand.end(); iter++){
            if (*iter==c){
                myHand.erase(myHand.begin()+cnt);
                return c;
            }
            cnt++;
        }
    }

    string Player::showHand() const{
        if (myHand.size()==0){
            return "No Cards in Hand.";
        }
        else {

            vector<Card>::const_iterator iter = myHand.begin();
            string handS = (*iter).toString() + " ";

            for (iter = myHand.begin() + 1; iter < myHand.end(); iter++) {
                handS = handS + (*iter).toString() + " ";
            }
            return handS;
        }

}
    string Player::showBooks() const{
        vector<Card>::const_iterator iter = myBook.begin();
        string bookS= (*iter).toString()+ " ";

        for (vector<Card>::const_iterator iter = myBook.begin()+1; iter < myBook.end(); iter++){
            bookS= bookS+ (*iter).toString()+ " ";
        }
        return bookS;
}

    int Player::getHandSize() const{
        int HandCount =0;
        for (vector<Card>::const_iterator iter = myHand.begin(); iter < myHand.end(); iter++){
            HandCount++;
        }
        return HandCount;
}

    int Player::getBookSize() const{
        int BookCount =0;
        for (vector<Card>::const_iterator iter = myBook.begin(); iter < myBook.end(); iter++){
            BookCount++;
        }
        return BookCount;
    }


    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//    bool Player::checkHandForPair(Card &c1, Card &c2){}

    //OPTIONAL
    // comment out if you decide to not use it
    //Does the player have a card with the same rank as c in her hand?
    //e.g. will return true if the player has a 7d and the parameter is 7c

//    bool Player::sameRankInHand(Card c) const{}




