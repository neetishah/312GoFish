// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    ofstream myfile;
    myfile.open("GoFish_Results.txt");

    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);


//    cout << p1.getName() <<" has : " << p1.showHand() << endl;
//    cout << p2.getName() <<" has : " << p2.showHand() << endl;
    myfile << p1.getName() <<" has : " << p1.showHand() << endl;
    myfile << p2.getName() <<" has : " << p2.showHand() << endl;

    int playFlag = 1;


    while ((p1.getBookSize() + p2.getBookSize()) !=52){
//        cout << "deck size: " <<d.size()<<endl;
//        if (d.size() == 0){
//            cout << p1.getName() << " has : " << p1.showBooks() << endl;
//            cout << p2.getName() << " has : " << p2.showBooks() << endl;
//        }

        if (playFlag) {


            if(p1.getHandSize()!=0) {

                Card c1 = p1.chooseCardFromHand();

//                cout << p1.getName() << " has : " << p1.showHand() << endl;
//                cout << p2.getName() << " has : " << p2.showHand() << endl;
//                cout << p1.getName() << " picked card from hand to ask next:" << c1 << endl << endl << endl;

//                cout << p1.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
                myfile << p1.getName() << " asks - Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;

                if (p2.rankInHand(c1)) {
//                    cout << p2.getName() << " says - Yes, I have a " << c1.rankString(c1.getRank()) << "." << endl;
                    myfile << p2.getName() << " says - Yes, I have a " << c1.rankString(c1.getRank()) << "." << endl;

                    Card checkSpade(c1.getRank(), Card::spades);
                    if (p2.cardInHand(checkSpade)) {
                        p1.bookCards(c1, checkSpade);
//                        cout<< p1.getName()<< " books "<< c1.getRank()<< "."<<endl<<endl;
                        myfile<< p1.getName()<< " books "<< c1.getRank()<< "."<<endl<<endl;
                        p2.removeCardFromHand(checkSpade);
                        p1.removeCardFromHand(c1);
                    } else {
                        Card checkHeart(c1.getRank(), Card::hearts);
                        if (p2.cardInHand(checkHeart)) {
                            p1.bookCards(c1, checkHeart);
//                            cout<< p1.getName()<< " books "<< c1.getRank()<< "."<<endl<<endl;
                            myfile<< p1.getName()<< " books "<< c1.getRank()<< "."<<endl<<endl;
                            p2.removeCardFromHand(checkHeart);
                            p1.removeCardFromHand(c1);
                        } else {
                            Card checkDiamond(c1.getRank(), Card::diamonds);
                            if (p2.cardInHand(checkDiamond)) {
                                p1.bookCards(c1, checkDiamond);
//                                cout<< p1.getName()<< " books "<< c1.getRank()<< "."<<endl<<endl;
                                myfile<< p1.getName()<< " books "<< c1.getRank()<< "."<<endl<<endl;
                                p2.removeCardFromHand(checkDiamond);
                                p1.removeCardFromHand(c1);
                            } else {
                                Card checkClub(c1.getRank(), Card::clubs);
                                if (p2.cardInHand(checkClub)) {
                                    p1.bookCards(c1, checkClub);
//                                    cout<< p1.getName()<< " books "<< c1.getRank()<< "."<<endl<<endl;
                                    myfile<< p1.getName()<< " books "<< c1.getRank()<< "."<<endl<<endl;
                                    p2.removeCardFromHand(checkClub);
                                    p1.removeCardFromHand(c1);
                                }
                            }
                        }
                    }

                } else {
//                    cout << p2.getName() << " says - Go Fish" << endl;
                    myfile << p2.getName() << " says - Go Fish" << endl;
                    if (d.size() > 0) {
                        Card deal = d.dealCard();
//                        cout<< p1.getName() <<" draws "<< deal <<" from deck"<< endl<<endl;
                        myfile<< p1.getName() <<" draws "<< deal <<" from deck"<< endl<<endl;
                        p1.addCard(deal);
                        if (p1.checkHandForBook(c1, deal)) {
                            p1.bookCards(c1, deal);
//                            cout<< p1.getName()<< " books "<< c1.getRank()<< "."<<endl<<endl;
                            myfile<< p1.getName()<< " books "<< c1.getRank()<< "."<<endl<<endl;
                            p1.removeCardFromHand(c1);
                            p1.removeCardFromHand(deal);
                        }
                    }

                }
            }

            else {
//                cout << "p1 shows hand before drawing:"<< p1.showHand()<<endl;
                if (d.size() != 0) {
                    p1.addCard(d.dealCard());
//                    cout << p1.getName() << " has no cards in hand. " << p1.getName() << " draws a card." << endl;
                    myfile << p1.getName() << " has no cards in hand. " << p1.getName() << " draws a card." << endl;
                }
                else {
//                    cout << "Deck is empty. " << p1.getName()<< " does not draw card."<< endl;
                    myfile << "Deck is empty. " << p1.getName()<< " does not draw card."<< endl;
                }
            }

            playFlag=0;

        }

        else {

            if(p2.getHandSize()!=0) {


                Card c2 = p2.chooseCardFromHand();

//                cout << p1.getName() << " has : " << p1.showHand() << endl;
//                cout << p2.getName() << " has : " << p2.showHand() << endl;
//                cout << p2.getName() << " picked card from hand to ask next:" << c2 << endl << endl << endl;

//                cout << p2.getName() << " asks - Do you have a " << c2.rankString(c2.getRank()) << "?" << endl;
                myfile << p2.getName() << " asks - Do you have a " << c2.rankString(c2.getRank()) << "?" << endl;
                if (p1.rankInHand(c2)) {
//                    cout << p1.getName() << " says - Yes, I have a " << c2.rankString(c2.getRank()) << "." << endl<<endl;
                    myfile << p1.getName() << " says - Yes, I have a " << c2.rankString(c2.getRank()) << "." << endl<<endl;
                    Card checkSpade(c2.getRank(), Card::spades);
                    if (p1.cardInHand(checkSpade)) {
                        p2.bookCards(c2, checkSpade);
//                        cout<< p2.getName()<< " books "<< c2.getRank()<< "."<<endl<<endl;
                        myfile<< p2.getName()<< " books "<< c2.getRank()<< "."<<endl<<endl;
                        p1.removeCardFromHand(checkSpade);
                        p2.removeCardFromHand(c2);
                    } else {
                        Card checkHeart(c2.getRank(), Card::hearts);
                        if (p1.cardInHand(checkHeart)) {
                            p2.bookCards(c2, checkHeart);
//                            cout<< p2.getName()<< " books "<< c2.getRank()<< "."<<endl<<endl;
                            myfile<< p2.getName()<< " books "<< c2.getRank()<< "."<<endl<<endl;
                            p1.removeCardFromHand(checkHeart);
                            p2.removeCardFromHand(c2);
                        } else {
                            Card checkDiamond(c2.getRank(), Card::diamonds);
                            if (p1.cardInHand(checkDiamond)) {
                                p2.bookCards(c2, checkDiamond);
//                                cout<< p2.getName()<< " books "<< c2.getRank()<< "."<<endl<<endl;
                                myfile<< p2.getName()<< " books "<< c2.getRank()<< "."<<endl<<endl;
                                p1.removeCardFromHand(checkDiamond);
                                p2.removeCardFromHand(c2);
                            } else {
                                Card checkClub(c2.getRank(), Card::clubs);
                                if (p1.cardInHand(checkClub)) {
                                    p2.bookCards(c2, checkClub);
//                                    cout<< p2.getName()<< " books "<< c2.getRank()<< "."<<endl<<endl;
                                    myfile<< p2.getName()<< " books "<< c2.getRank()<< "."<<endl<<endl;
                                    p1.removeCardFromHand(checkClub);
                                    p2.removeCardFromHand(c2);
                                }
                            }
                        }
                    }

                } else {
//                    cout << p1.getName() << " says - Go Fish" << endl<<endl;
                    myfile << p1.getName() << " says - Go Fish" << endl<<endl;
                    if (d.size() > 0) {
                        Card deal = d.dealCard();
//                        cout<< p2.getName() <<" draws "<< deal <<" from deck"<< endl<<endl;
                        myfile<< p2.getName() <<" draws "<< deal <<" from deck"<< endl<<endl;
                        p2.addCard(deal);
//                        cout<< "now p2 has: "<< p2.showHand() << endl;
                        if (p2.checkHandForBook(c2, deal)) {
                            p2.bookCards(c2, deal);
//                            cout<< p2.getName()<< " books "<< c2.getRank()<< "."<<endl;
                            myfile<< p2.getName()<< " books "<< c2.getRank()<< "."<<endl;
                            p2.removeCardFromHand(c2);
                            p2.removeCardFromHand(deal);
                        }
                    }
                }
            }
            else {

//                cout << "p2 shows hand before drawing:"<< p2.showHand()<<endl;
                if (d.size() != 0) {
                    p2.addCard(d.dealCard());
//                    cout << p2.getName() << " has no cards in hand." << p2.getName() << " draws a card." << endl;
                    myfile << p2.getName() << " has no cards in hand." << p2.getName() << " draws a card." << endl;
                }
                else {
//                    cout << "Deck is empty. " << p2.getName()<< " does not draw card."<< endl;
                    myfile << "Deck is empty. " << p2.getName()<< " does not draw card."<< endl;
                }
//                cout << "p2 shows hand after drawing:"<< p2.showHand()<<endl;
            }

            playFlag=1;

        }

    }


    int p1BookSize = p1.getBookSize();
    int p2BookSize = p2.getBookSize();

//    cout<< "End of Game. The 26 books are shown below:"<<endl;
    myfile<< "End of Game. The 26 books are shown below:"<<endl;
//    cout << p1.getName() << "'s books: "<< p1.showBooks()<< endl;
//    cout << p2.getName() << "'s books: "<< p2.showBooks()<<endl<<endl;
    myfile << p1.getName() << "'s books: "<< p1.showBooks()<< endl;
    myfile << p2.getName() << "'s books: "<< p2.showBooks()<<endl<<endl;

    if (p1BookSize > p2BookSize){
//        cout << p1.getName() << " wins!"<< endl;
        myfile << p1.getName() << " wins!"<< endl;
    }
    else if (p2BookSize > p1BookSize){
//        cout << p2.getName() << " wins!"<< endl;
        myfile << p2.getName() << " wins!"<< endl;
    }
    else {
//        cout << "Tie Game." << endl;
        myfile << "Tie Game." << endl;
    }



    myfile.close();


    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}
   


