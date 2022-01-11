// BlackJackCPPProjekt.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Deck.h"

int main()
{
    std::cout << "Hello World!\n";
}

class BlackJack{
    //initialize ImageViews



    bool endRound = false;
    int playerMoney = 300;
    int playerValue;
    int playerBet;
    int cardNumber = 0;

    Deck playingDeck = Deck();
    //Create a deck for the player
    Deck playerDeck = Deck();

    Deck dealerDeck = Deck();


    //setting players bet
public:
    void setBet() {
        std::cout << "You have " << playerMoney << "$\n How much would you like to bet?";
  //      PlayerMoney.setText("" + playerMoney + "$");

   /*     EnterBtn.setOnClickListener(new View.OnClickListener() {
            @Override
                public void onClick(View view) {
                try {
                    playerBet = Integer.parseInt(PlayerInput.getText().toString());
                    EnterBtn.setEnabled(false);
                    if (PlayerInput.length() > 0) {
                        GameText.setText(GameText.getText() + "\nYour bet is " + playerBet);
                        if (playerBet > playerMoney) {
                            System.out.println("You haven't got enough money. You've been kicked out");

                            GameText.setText(GameText.getText() + "\nYou haven't got enough money. You've been kicked out");
                            WinLosePush.setText("You haven't got enough money. You've been kicked out");
                            GameText.setText(GameText.getText() + "\nWould you like to play again?\n(1)YES/(2)NO");
                            stand.setEnabled(false);
                            hit.setEnabled(false);
                            play.setEnabled(true);
                        }
                        else {
                            PLAY();
                        }

                    }
                }
                catch (Exception e) {
                    e.printStackTrace();
                    playerBet = 0;
                }
            }
        });*/
    }

    void PLAY() {
    /*    YourPoints.setText("");
        DealerPoints.setText("");
        WinLosePush.setText("");*/

        playingDeck.createFullDeck();
        playingDeck.shuffle();

        playerDeck.draw(playingDeck);
        playerDeck.draw(playingDeck);

        //Dealer gets two cards
        dealerDeck.draw(playingDeck);
        dealerDeck.draw(playingDeck);

        //add card view here

   /*    ViewCard(playerDeck, 0, imageView1);
        ViewCard(playerDeck, 1, imageView2);*/
        cardNumber = 1;

     //   ViewCard(dealerDeck, 0, imageView7);



    //    System.out.println("Your hand:");
        std::cout << "Your hand" << std::endl;
       // System.out.println(playerDeck.toString());
        std::cout << playerDeck.toString()<< std::endl;

        std::cout<<"Your deck is valued at: " + playerDeck.cardsValue()<<std::endl;

        playerValue = playerDeck.cardsValue();
       // YourPoints.setText(playerValue + "");


        if (playerDeck.deckSize() == 2 && playerValue == 21) {
          //  System.out.println("BlackJack");
            std::cout << "BlackJack" << std::endl;
            playerMoney += playerBet;
            playerDeck.moveAllToDeck(playingDeck);
            dealerDeck.moveAllToDeck(playingDeck);
        //    System.out.println("End of hand.");

        }

      //  GameText.setText(GameText.getText() + "\nDealer hand:\n" + dealerDeck.getCard(0).toString() + " and [HIDDEN]");

   //     GameText.setText(GameText.getText() + "\nWould you like to HIT or Stand?");
   //     hit.setEnabled(true);
   //     stand.setEnabled(true);

    }

    void HIT(View view) {
        cardNumber = cardNumber + 1;
        ImageView imageView = null;
        if (cardNumber == 2) {
            imageView = imageView3;
        }
        else if (cardNumber == 3) {
            imageView = imageView4;
        }
        else if (cardNumber == 4) {
            imageView = imageView5;
        }
        else if (cardNumber == 5) {
            imageView = imageView6;
        }
        playerDeck.draw(playingDeck);
        ViewCard(playerDeck, cardNumber, imageView);

        System.out.println("You draw a: " + playerDeck.getCard(playerDeck.deckSize() - 1).toString());
        //  GameText.setText(GameText.getText() + "\nYou draw a: "+playerDeck.getCard(playerDeck.deckSize() - 1).toString());
        System.out.println("Currently valued at: " + playerDeck.cardsValue());
        GameText.setText(GameText.getText() + "\nCurrently valued at: " + playerDeck.cardsValue());
        playerValue = playerDeck.cardsValue();
        YourPoints.setText(playerValue + "");
        //Bust if over 21
        if (playerDeck.cardsValue() > 21) {
            System.out.println("Bust. Currently valued at: " + playerDeck.cardsValue());
            System.out.println("Dealer wins");
            GameText.setText(GameText.getText() + "\nBust.Currently valued at: " + playerDeck.cardsValue() + "\nDealer wins");
            YourPoints.setText(playerValue + "");
            //winlosepush
            WinLosePush.setText("Bust.Dealer wins");

            playerDeck.moveAllToDeck(playingDeck);
            dealerDeck.moveAllToDeck(playingDeck);
            System.out.println("End of hand.");
            GameText.setText(GameText.getText() + "\nEnd of hand");
            GameText.setText(GameText.getText() + "\nWould you like to play again?\nYES/NO?");

            stand.setEnabled(false);
            hit.setEnabled(false);
            play.setEnabled(true);

            playerMoney -= playerBet;

            endRound = true;
        }
        else if (playerDeck.cardsValue() == 21) {
            GameText.setText(GameText.getText() + "\nYou can only STAND now");
            hit.setEnabled(false);
        }
        else {
            GameText.setText(GameText.getText() + "\nWould you like to HIT or Stand?");
        }
    }

    void STAND(View view) {
        int dealerCardNumber = 1;

        while (true) {
            if (dealerDeck.cardsValue() <= 16) {
              //  System.out.println("Dealer is drawing...");
        //        GameText.setText(GameText.getText() + "\nDealer is drawing...");
                dealerDeck.draw(playerDeck);
                dealerCardNumber = dealerCardNumber + 1;
                break;
            }
            else {
                break;
            }
        }



    //    System.out.println("Dealer cards: " + dealerDeck.toString());
   //     GameText.setText(GameText.getText() + "\nDealer cards: " + dealerDeck.toString());
    //    System.out.println("Your cards value: " + playerValue);
    //    YourPoints.setText(playerValue + "");
        GameText.setText(GameText.getText() + "\nDealer is drawing...");


        System.out.println("Dealer cards value: " + dealerDeck.cardsValue());
     //   DealerPoints.setText(dealerDeck.cardsValue() + "");
        GameText.setText(GameText.getText() + "\nDealer cards value: " + dealerDeck.cardsValue());
        System.out.println("dealer card number =" + dealerCardNumber);

        for (int i = 1; i <= dealerCardNumber; i++) {
            switch (i) {
            case 1:
                ViewCard(dealerDeck, 1, imageView8);
                break;

            case 2:
                ViewCard(dealerDeck, 2, imageView9);
                break;
            case 3:
                ViewCard(dealerDeck, 3, imageView10);
                break;
            case 4:
                ViewCard(dealerDeck, 4, imageView11);
                break;


            }

        }

        if (playerDeck.cardsValue() == 21 && playerDeck.deckSize() == 2) {
            WinLosePush.setText("BLACKJACK.YOU WON");
        }

        if (dealerDeck.cardsValue() > playerValue && dealerDeck.cardsValue() <= 21) {
            System.out.println("You lost.");
            //  GameText.setText(GameText.getText() + "\nYou lost");
            WinLosePush.setText("You lost");

            playerMoney -= playerBet;
            endRound = true;
        }

        if (dealerDeck.cardsValue() > 21) {
            System.out.println("Dealer bust. You won");
            WinLosePush.setText("Dealer is busted. You won");

            //   GameText.setText(GameText.getText() + "\nDealer busted.You won");
            playerMoney += playerBet;
            endRound = true;
        }
        if (dealerDeck.cardsValue() < playerValue) {
            System.out.println("You won");
            //  GameText.setText(GameText.getText() + "\nYou won");
            WinLosePush.setText("You won");

            playerMoney += playerBet;
            endRound = true;
        }
        if (dealerDeck.cardsValue() == playerValue) {
            System.out.println("Push");
            //  GameText.setText(GameText.getText() + "\nPush");
            WinLosePush.setText("Push");

            endRound = true;
        }

        playerDeck.moveAllToDeck(playingDeck);
        dealerDeck.moveAllToDeck(playingDeck);
        System.out.println("End of hand.");
        //  GameText.setText(GameText.getText() + "\nEnd of hand");
        hit.setEnabled(false);
        stand.setEnabled(false);

        if (playerMoney > 0) {
            //    GameText.setText(GameText.getText() + "\nWould you like to play again?\nYES/NO?");

            hit.setEnabled(false);
            stand.setEnabled(false);
            play.setEnabled(true);

        }
        if (playerMoney == 0) {
            // GameText.setText(GameText.getText() + "\nYou lost all your money :( Try again later");
            WinLosePush.setText("You lost all your money :( Try again later");
            hit.setEnabled(false);
            stand.setEnabled(false);
            play.setEnabled(false);

        }
    }

    void PLAY_AGAIN(View view) {
        play.setEnabled(false);
        WinLosePush.setText("");
        DealerPoints.setText("");
        YourPoints.setText("");
        PlayerMoney.setText(playerMoney + "");
       

        onStart();
    }

    void LEAVE(View view) {
        //   GameText.setText("So you want to leave,okey...");
    //    WinLosePush.setText("So you want to leave,okey...");
        playerDeck.moveAllToDeck(playingDeck);
        dealerDeck.moveAllToDeck(playingDeck);
     //   System.out.println("End of hand.");
     //   GameText.setText(GameText.getText() + "\nEnd of hand");
        if (playerMoney < 300)
        {
           /* GameText.setText(GameText.getText() + "\nYou lost: " + (300 - playerMoney) + "$");
            hit.setEnabled(false);
            stand.setEnabled(false);
            EnterBtn.setEnabled(false);*/
        }
        else if (playerMoney >= 300) {
         /*   GameText.setText(GameText.getText() + "\nCongratulation,you won: " + (playerMoney - 300) + "$");

            hit.setEnabled(false);
            stand.setEnabled(false);
            EnterBtn.setEnabled(false);*/
        }
        playerMoney = 300;
   //     play.setEnabled(true);
    }


    /*   public void ViewCard(Deck playerDeck, int g, ImageView imageView) {
           Deck cards;
           int i = g;


           cards = playerDeck;


           Card card = cards.getCard(i);
           switch (card.getValue()) {
           case Suit::ACE:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.ace1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.ace2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.ace3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.ace4);
                   break;

               }
               break;
           case KING:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.king1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.king2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.king3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.king4);
                   break;


               }
               break;
           case QUEEN:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.queen1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.queen1);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.queen1);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.queen1);
                   break;

               }
               break;
           case JACK:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.jack1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.jack1);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.jack1);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.jack1);
                   break;

               }
               break;
           case TEN:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.ten1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.ten2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.ten3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.ten4);
                   break;
               }
               break;
           case NINE:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.nine1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.nine2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.nine3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.nine4);
                   break;
               }
               break;
           case EIGHT:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.eight1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.eight2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.eight3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.eight4);
                   break;
               }
               break;
           case SEVEN:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.seven1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.seven2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.seven3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.seven4);
                   break;
               }
               break;
           case SIX:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.six1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.six2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.six3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.six4);
                   break;

               }
               break;
           case FIVE:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.five1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.five2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.five3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.five4);
                   break;

               }
               break;
           case FOUR:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.four1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.four2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.four3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.four4);
                   break;

               }
               break;
           case THREE:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.three1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.three2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.three3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.three4);
                   break;

               }
               break;
           case TWO:
               switch (card.getSuit()) {
               case HEART:
                   imageView.setBackgroundResource(R.drawable.two1);
                   break;
               case CLUB:
                   imageView.setBackgroundResource(R.drawable.two2);
                   break;
               case SPADE:
                   imageView.setBackgroundResource(R.drawable.two3);
                   break;
               case DIAMOND:
                   imageView.setBackgroundResource(R.drawable.two4);
                   break;

               }
           }

       }*/ //Show cards

}
}
