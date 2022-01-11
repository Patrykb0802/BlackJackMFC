#pragma once
#include <iostream>
#include "Card.h"
#include <vector>
#include <algorithm>
#include <map>
#include "Value.h"
#include "Suit.h"


class Deck
{


private: 
    std::vector<Card> cards;
    /*
    std::initializer_list<Suit::Suits> all_Suits = { Suit::CLUB,Suit::DIAMOND,Suit::SPADE,Suit::HEART };
   

   
    std::initializer_list<Value::Values> all_Values = {
      Value::TWO,Value::THREE,Value::FOUR,Value::FIVE,
      Value::SIX,Value::SEVEN,Value::EIGHT,
      Value::NINE,Value::TEN,Value::JACK,
      Value::QUEEN,Value::KING,Value::ACE
    };
    */

public:
    //construct
    Deck() {
        cards = std::vector<Card>();
    }

    void createFullDeck() {
        //Generate Card Deck
        for (int suitInt = Suit::CLUB; suitInt != Suit::LAST; suitInt++) {
            for (int cardInt = Value::TWO; cardInt != Value::LAST; cardInt++) {
                //Add a new card to the mix
                Card card = Card(static_cast<Suit::Suits>(suitInt), static_cast<Value::Values>(cardInt));
                cards.push_back(card);
            }
        }
    }

    /*
    void createFullDeck() {
        //Generate Card Deck
        for (auto cardSuit : all_Suits) {
            for (auto cardValue : all_Values) {
                //Add a new card to the mix
                Card card = Card(cardSuit, cardValue);
                cards.push_back(card);
            }
        }
    }
    */
    void moveAllToDeck(Deck moveTo) {
        int thisDeckSize = cards.size();

        for (int i = 0; i < thisDeckSize; i++)
        {
            moveTo.addCard(getCard(i));
        }

        for (int i = 0; i < thisDeckSize; i++)
        {
            removeCard(0);
        }
    }

    void shuffle() {
        std::random_shuffle(cards.begin(), cards.end());

    }

    int deckSize() {
        return cards.size();
    }

    std::string toString() {
        std::string cardListOutput = "";

        for (Card aCard : cards)
        {
            cardListOutput += "\n " + aCard.toString();

        }
        return cardListOutput;
    }

    void removeCard(int i) {
        cards.erase(cards.begin() + i);
    }

    Card getCard(int i) {
        return cards[i];
    }

    void addCard(Card addCard) {
        cards.push_back(addCard);
    }

    //Draw from the deck
    void draw(Deck comingFrom) {
        cards.push_back(comingFrom.getCard(0));
        comingFrom.removeCard(0);

    }

    //Return value of your hand cards
    int cardsValue() {
        int totalValue = 0;
        int aces = 0;

        for (Card aCard : cards)
        {
            switch (aCard.getValue())
            {
            case Value::TWO: totalValue += 2; break;
            case Value::THREE: totalValue += 3; break;
            case Value::FOUR: totalValue += 4; break;
            case Value::FIVE: totalValue += 5; break;
            case Value::SIX: totalValue += 6; break;
            case Value::SEVEN: totalValue += 7; break;
            case Value::EIGHT: totalValue += 8; break;
            case Value::NINE: totalValue += 9; break;
            case Value::TEN: totalValue += 10; break;
            case Value::JACK: totalValue += 10; break;
            case Value::QUEEN: totalValue += 10; break;
            case Value::KING: totalValue += 10; break;
            case Value::ACE: aces += 1; break;
            }
        }

        for (int i = 0; i < aces; i++)
        {
            if (totalValue > 10)
            {
                totalValue += 1;
            }
            else
            {
                totalValue += 11;
            }
        }
        return totalValue;
    }
};

