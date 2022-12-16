// Casino: Building a BlackJack game to practice software engineering skills like kanban and iteration of work. General planning and refinement along the way.

#include "card.h"
#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

//void startGame(Player& player, Player& dealer);

int main()
{   
    //Used to create a seed for random number generator
    srand((unsigned)time(NULL));
    
    //Deck
    std::vector<card> deck;
    card ace_D("Ace", "Diamonds", 11);
    card ace_H("Ace", "Hearts", 11);
    card ace_C("Ace", "Clubs", 11);
    card ace_S("Ace", "Spades", 11);
    deck.push_back(ace_D);
    deck.push_back(ace_H);
    deck.push_back(ace_C);
    deck.push_back(ace_S);

    card two_D("Two", "Diamonds", 2);
    card two_H("Two", "Hearts", 2);
    card two_C("Two", "Clubs", 2);
    card two_S("Two", "Spades", 2);
    deck.push_back(two_D);
    deck.push_back(two_H);
    deck.push_back(two_C);
    deck.push_back(two_S);

    card three_D("Three", "Diamonds", 3);
    card three_H("Three", "Hearts", 3);
    card three_C("Three", "Clubs", 3);
    card three_S("Three", "Spades", 3);
    deck.push_back(three_D);
    deck.push_back(three_H);
    deck.push_back(three_C);
    deck.push_back(three_S);

    card four_D("Four", "Diamonds", 4);
    card four_H("Four", "Hearts", 4);
    card four_C("Four", "Clubs", 4);
    card four_S("Four", "Spades", 4);
    deck.push_back(four_D);
    deck.push_back(four_H);
    deck.push_back(four_C);
    deck.push_back(four_S);

    card five_D("Five", "Diamonds", 5);
    card five_H("Five", "Hearts", 5);
    card five_C("Five", "Clubs", 5);
    card five_S("Five", "Spades", 5);
    deck.push_back(five_D);
    deck.push_back(five_H);
    deck.push_back(five_C);
    deck.push_back(five_S);

    card six_D("Six", "Diamonds", 6);
    card six_H("Six", "Hearts", 6);
    card six_C("Six", "Clubs", 6);
    card six_S("Six", "Spades", 6);
    deck.push_back(six_D);
    deck.push_back(six_H);
    deck.push_back(six_C);
    deck.push_back(six_S);

    card seven_D("Seven", "Diamonds", 7);
    card seven_H("Seven", "Hearts", 7);
    card seven_C("Seven", "Clubs", 7);
    card seven_S("Seven", "Spades", 7);
    deck.push_back(seven_D);
    deck.push_back(seven_H);
    deck.push_back(seven_C);
    deck.push_back(seven_S);

    card eight_D("Eight", "Diamonds", 8);
    card eight_H("Eight", "Hearts", 8);
    card eight_C("Eight", "Clubs", 8);
    card eight_S("Eight", "Spades", 8);
    deck.push_back(eight_D);
    deck.push_back(eight_H);
    deck.push_back(eight_C);
    deck.push_back(eight_S);

    card nine_D("Nine", "Diamonds", 9);
    card nine_H("Nine", "Hearts", 9);
    card nine_C("Nine", "Clubs", 9);
    card nine_S("Nine", "Spades", 9);
    deck.push_back(nine_D);
    deck.push_back(nine_H);
    deck.push_back(nine_C);
    deck.push_back(nine_S);

    card ten_D("Ten", "Diamonds", 10);
    card ten_H("Ten", "Hearts", 10);
    card ten_C("Ten", "Clubs", 10);
    card ten_S("Ten", "Spades", 10);
    deck.push_back(ten_D);
    deck.push_back(ten_H);
    deck.push_back(ten_C);
    deck.push_back(ten_S);

    card jack_D("Jack", "Diamonds", 10);
    card jack_H("Jack", "Hearts", 10);
    card jack_C("Jack", "Clubs", 10);
    card jack_S("Jack", "Spades", 10);
    deck.push_back(jack_D);
    deck.push_back(jack_H);
    deck.push_back(jack_C);
    deck.push_back(jack_S);

    card queen_D("Queen", "Diamonds", 10);
    card queen_H("Queen", "Hearts", 10);
    card queen_C("Queen", "Clubs", 10);
    card queen_S("Queen", "Spades", 10);
    deck.push_back(queen_D);
    deck.push_back(queen_H);
    deck.push_back(queen_C);
    deck.push_back(queen_S);

    card king_D("King", "Diamonds", 10);
    card king_H("King", "Hearts", 10);
    card king_C("King", "Clubs", 10);
    card king_S("King", "Spades", 10);
    deck.push_back(king_D);
    deck.push_back(king_H);
    deck.push_back(king_C);
    deck.push_back(king_S);

    std::sort(deck.begin(), deck.end());
    //In future add more decks - meant to decrease ability to count cards by adding more decks to dealer's shoe 
    std::queue<card> shoe;


    std::vector<card>temp;

    for (int i = 0; i < deck.size() - 1; i++)
    {
        //std::cout << temp[i].order_num << temp[i].name << " of " << temp[i].suit << std::endl;
        //std::cout << "DECK: " << deck[i].name << " of " << deck[i].suit << std::endl;
        shoe.push(deck[i]);
    }
        
    //Player
    class Player
    {
    public:
        std::string name;
        std::int16_t score;
        std::int16_t handValue;
        std::int16_t numOfCardsDealt;
        std::vector<card> hand;

        Player()
        {
            name = "";
            score = 0;
            handValue = 0;
            numOfCardsDealt = 0;
            hand.clear();

        }

        void playerWin()
        {
            score += 1;
            hand.clear();
        };

        void playerLose()
        {
            score -= 1;
            hand.clear();
        };

        void playerDealOne(std::queue<card>& shoe)
        {
            hand.push_back(shoe.front());
            shoe.pop();
        }

        void playerHit(std::queue<card>& shoe)
        {
            std::string userInput;
            std::string hit = "hit";
            std::string stay = "stay";

            std::cout << "Does " << name << " want another card?" << std::endl;
            std::cout << "Enter hit for another card or stay: \n";
            std::cin >> userInput;

            if (userInput == hit)
            {
                if (!shoe.empty())
                {
                    playerDealOne(shoe);
                }
            }
            else if (userInput == stay)
            {
                //TODO - call end of round - showHand function
            }
            else
            {
                std::cout << "Invalid entry, try again.\n";
                playerHit(shoe);
            }
        };

        void getPlayerHandValue()
        {
            if (!hand.empty())
            {
                handValue = 0;
                numOfCardsDealt = int16_t(hand.size());
                for (int16_t i = 0; i < numOfCardsDealt; i++)
                {
                    handValue += hand[i].value;
                }
            }
        };

        void updatePlayerHandValue()
        {
            getPlayerHandValue();
            int aceCount = 0;

            if (handValue < 21)
            {
                handValue = handValue;
            }

            if (handValue == 21)
            {
                playerWin();
            }

            else if (hand.size() >= 3 && handValue > 21)
            {
                for (int i = 0; i < hand.size() - 1; i++)
                {
                    if (hand[i].name == "Ace")
                    {
                        aceCount += 1;
                    }
                }
                if (aceCount == 0)
                {
                    playerLose();
                }
                if (aceCount == 1)
                {
                    for (int i = 0; i < hand.size() - 1; i++)
                    {
                        if (hand[i].name == "Ace")
                        {
                            hand[i].value = 1;
                            updatePlayerHandValue();
                        }
                    }
                    if (aceCount >= 2)
                    {
                        for (int i = 0; i < hand.size() - 1; i++)
                        {
                            if (hand[i].name == "Ace")
                            {
                                hand[i].value = 1;
                                break;
                            }
                        }
                    }
                }
            }
        };



        void Status()
        {
            //updatePlayerHandValue();
            getPlayerHandValue();
            std::cout << name << "\t\t" << "Score: " << score << "\t" << "Hand Value: " << handValue << "\tCards in hand: " << numOfCardsDealt << "\n";
            for (int i = 0; i < numOfCardsDealt; i++) { std::cout << "\t" << hand[i].name << " of " << hand[i].suit << "\t"; }
            std::cout << std::endl;
        };
    };

    Player player;
    Player dealer;
    dealer.name = "Dealer";

    ////Dealer
    //class Dealer
    //{
    //public:
    //    std::int16_t score;
    //    std::int16_t handValue;
    //    std::int16_t numOfCardsDealt;
    //    std::vector<card> hand;

    //    Dealer()
    //    {
    //        score = 0;
    //        handValue = 0;
    //        numOfCardsDealt = 0;
    //        hand.clear();
    //    }

    //    void dealerWin(Player &player)
    //    {
    //        score += 1;
    //        hand.clear();
    //        player.playerLose();
    //    }

    //    void dealerLose(Player& player)
    //    {
    //        score -= 1;
    //        hand.clear();
    //        player.playerWin();
    //    }

    //    void dealerDealOne(std::queue<card>& shoe)
    //    {
    //        hand.push_back(shoe.front());
    //        shoe.pop();
    //    }

    //    void getDealerHandValue()
    //    {
    //        if (!hand.empty())
    //        {
    //            handValue = 0;
    //            numOfCardsDealt = hand.size();
    //            for (int16_t i = 0; i < numOfCardsDealt; i++)
    //            {
    //                handValue += hand[i].value;
    //            }
    //        }
    //    };

    //    void updateDealerHandValue()
    //    {
    //        getDealerHandValue();
    //        int aceCount = 0;

    //        if (handValue < 21)
    //        {
    //            handValue = handValue;
    //        }

    //        else if (hand.size() >= 3 && handValue > 21)
    //        {
    //            for (int i = 0; i < hand.size() - 1; i++)
    //            {
    //                if (hand[i].name == "Ace")
    //                {
    //                    aceCount += 1;
    //                }
    //            }
    //            if (aceCount == 0)
    //            {
    //                
    //            }
    //            if (aceCount == 1)
    //            {
    //                for (int i = 0; i < hand.size() - 1; i++)
    //                {
    //                    if (hand[i].name == "Ace")
    //                    {
    //                        hand[i].value = 1;
    //                    }
    //                }
    //                if (aceCount >= 2)
    //                {
    //                    for (int i = 0; i < hand.size() - 1; i++)
    //                    {
    //                        if (hand[i].name == "Ace")
    //                        {
    //                            hand[i].value = 1;
    //                            break;
    //                        }
    //                    }
    //                }
    //            }
    //        }
    //    };

    //    void Status()
    //    {
    //        //updateDealerHandValue();
    //        getDealerHandValue();
    //        std::cout << "Dealer: CPU" << "\t\tHand Value: " << handValue << "\tCards in hand: " << numOfCardsDealt << "\t";
    //        for (int i = 0; i < numOfCardsDealt; i++) { std::cout << hand[i].name << " of " << hand[i].suit << "\t"; }
    //        std::cout << std::endl;
    //    };
    //};

    //Dealer dealer;
    
    void startGame(Player& player, Player& dealer);
    {


        int dealCards = 2;
        std::string userInput;

        std::cout << "What is the player's name?";
        std::cin >> player.name;

        dealer.Status();
        player.Status();

        if (!shoe.empty())
        {
            for (int i = 0; i < dealCards; i++)
            {
                //player.hand.push_back(shoe.front());
                //shoe.pop();
                player.playerDealOne(shoe);
                dealer.playerDealOne(shoe);
            }
        };

        dealer.Status();
        player.Status();

        while (true)//(player.handValue < dealer.handValue)
        {
            player.playerHit(shoe);

            dealer.Status();
            player.Status();
        }


    }





        //startGame(player, dealer);
}



    
   


    /* TODO - now have que full of cards 
     * need to create player and dealer with some state (commence play, how many cards in hand to end deal?)    
     * deal function - one card to each player and dealer before dealing second card
     * sum function - sums total value - shown to player, dealers hidden
     * win: player wins if 21 and dealer is less, dealer uncovers 21 if they are dealt it on first two cards (natural - 10 valued card plus ace)
     * lose: either player or dealer exceeds 21
     * dealer restrictions: can not take another card if at 17 or greater
     * Need to separate responsibilities with update and check for win status - causing conflict of updating information that is wiped clear
     * Dealer can just be an instance of player class, does not need a separate class if we build the functions outside of the player class
    */
  
    



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
