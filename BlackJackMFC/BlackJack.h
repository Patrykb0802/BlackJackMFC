#pragma once

#include "pch.h"
#include "framework.h"
#include "BlackJackMFC.h"
#include "BlackJackMFCDlg.h"
#include "afxdialogex.h"
#include "Deck.h"
#include "Value.h"
#include "Suit.h"
#include <sstream>
#include "resource.h"

CAboutDlg window = CAboutDlg();

class BlackJack {

    bool endRound = false;
    int playerMoney = 300;
    int playerValue;
    int playerBet;
    int cardNumber = 0;

    Deck playingDeck = Deck();
    //Create a deck for the player
    Deck playerDeck = Deck();

    Deck dealerDeck = Deck();

   

public:
    void setBet() {
        std::cout << "You have " << playerMoney << "$\n How much would you like to bet?";

        WinEnable(play, FALSE);
        if (playerBet > 0) {

            if (playerBet > playerMoney) {

                WinEnable(hit, FALSE);
                WinEnable(stand, FALSE);
                WinEnable(play, TRUE);
            }
        }
    }

    void PLAY() {

        setBet();
        playingDeck.createFullDeck();
        playingDeck.shuffle();

        playerDeck.draw(playingDeck);
        playerDeck.draw(playingDeck);

        //Dealer gets two cards
        dealerDeck.draw(playingDeck);
        dealerDeck.draw(playingDeck);

//add card view here


        cardNumber = 1;






        std::cout << "Your hand" << std::endl;

        std::cout << playerDeck.toString() << std::endl;

        std::cout << "Your deck is valued at: " + playerDeck.cardsValue() << std::endl;

        playerValue = playerDeck.cardsValue();



        if (playerDeck.deckSize() == 2 && playerValue == 21) {
            // BlackJack
            std::cout << "BlackJack" << std::endl;
            playerMoney += playerBet;
            playerDeck.moveAllToDeck(playingDeck);
            dealerDeck.moveAllToDeck(playingDeck);
           

        }

        

     //Would you like to HIT or Stand?
        WinEnable(hit, TRUE);
        WinEnable(stand, TRUE);

    }

    void HIT() {
        cardNumber = cardNumber + 1;
        
        if (cardNumber == 2) {
            
        }
        else if (cardNumber == 3) {
            
        }
        else if (cardNumber == 4) {
            
        }
        else if (cardNumber == 5) {
            
        }
        playerDeck.draw(playingDeck);
        


        playerValue = playerDeck.cardsValue();
        //Bust if over 21
        if (playerDeck.cardsValue() > 21) {    //FURA

            //Bust.Dealer wins

            playerDeck.moveAllToDeck(playingDeck);
            dealerDeck.moveAllToDeck(playingDeck);
            //End of hand.
            //Would you like to play again?\nYES/NO?

            WinEnable(stand, FALSE);
            WinEnable(hit, FALSE);
            WinEnable(play, TRUE);
            playerMoney -= playerBet;

            endRound = true;
        }
        else if (playerDeck.cardsValue() == 21) { // WYGRANA
            //You can only STAND now
            WinEnable(hit, FALSE);
        }
        else {
            //Would you like to HIT or Stand?
        }
    }

    void STAND() {
        int dealerCardNumber = 1;

        if (dealerDeck.cardsValue() <= 16) {

            dealerDeck.draw(playerDeck);
            dealerCardNumber = dealerCardNumber + 1;
            
        }

        if (playerDeck.cardsValue() == 21 && playerDeck.deckSize() == 2) {
           
        }

        if (dealerDeck.cardsValue() > playerValue && dealerDeck.cardsValue() <= 21) {

            playerMoney -= playerBet;
            endRound = true;
        }

        if (dealerDeck.cardsValue() > 21) {
            playerMoney += playerBet;
            endRound = true;
        }
        if (dealerDeck.cardsValue() < playerValue) {
            

            playerMoney += playerBet;
            endRound = true;
        }
        if (dealerDeck.cardsValue() == playerValue) {
          

            endRound = true;
        }

        playerDeck.moveAllToDeck(playingDeck);
        dealerDeck.moveAllToDeck(playingDeck);
        WinEnable(hit, FALSE);
        WinEnable(stand, FALSE);

        if (playerMoney > 0) {
            

            WinEnable(hit, FALSE);
            WinEnable(stand, FALSE);
            WinEnable(play, TRUE);

        }
        if (playerMoney == 0) {
            
            WinEnable(hit, FALSE);
            WinEnable(stand, FALSE);
            WinEnable(play, FALSE);

        }
    }

    void PLAY_AGAIN() {
        WinEnable(play, FALSE);
        

        WinEnable(play, TRUE);
    }



   
    void setText(int ID, std::string text) {
        window.setText(ID, text);                                  //tu podobnie jak na dole
    }

    void WinEnable(int ID, bool TF) {
        window.WinEnable(ID, TF);                     //Chcieliœmy siê odnieœæ do klasy CAboutDlg, b³¹d przy kompilacji
    }

};
