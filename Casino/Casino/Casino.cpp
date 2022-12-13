// Casino: Building a BlackJack game to practice software engineering skills like kanban and iteration of work. General planning and refinement along the way.

#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>

int main()
{   
    //Used to create a seed for random number generator
    srand((unsigned)time(NULL));

    //create prototype for a playing card
    class card
    {
        public:
            std::string name;
            std::string suit;        
            std::int16_t value;
            std::int16_t order_num;     //used for randomizing position of card in deck

            int random_value()
            {               
                int random = rand();
                return random;
            }                  

            //overload the less than comparator to allow sort() to work
            bool operator<(const card&rhs) 
            {
                return (order_num < rhs.order_num);       
            }

            //card constructor
            card(std::string p_name, std::string p_suit, std::int16_t p_value) 
            {
                name = p_name;
                suit = p_suit;
                value = p_value;
                order_num = random_value();
            }                       
    };

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
                hand.empty();

            }

            void updatePlayerHandValue() 
            {
                if (!hand.empty())
                {
                    numOfCardsDealt = hand.size();
                    for (int i = 0; i < numOfCardsDealt; i++)
                    {
                        handValue += hand[i].value;
                    }
                }
                 
            };
            void Status()
            {
                updatePlayerHandValue();
                std::cout << "Player: " << name << "\t\t" << "Hand Value: " << handValue << "\tCards in hand: " << numOfCardsDealt << "\t";
                for (int i = 0; i < numOfCardsDealt; i++) { std::cout << hand[i].name << " of " << hand[i].suit << "\t"; }
                std::cout << std::endl;
            };
    };

    //Dealer
    class Dealer 
    {
        public:
            std::int16_t score;
            std::int16_t handValue;
            std::int16_t numOfCardsDealt;
            std::vector<card> hand;
            
            Dealer() 
            {
                score = 0;
                handValue = 0;
                numOfCardsDealt = 0;
                hand.empty();
            }

            void updateDealerHandValue()
            {
                if (!hand.empty())
                {
                    numOfCardsDealt = hand.size();
                    for (int i = 0; i < numOfCardsDealt; i++)
                    {
                        handValue += hand[i].value;
                    }
                    
                    
                }
            };
            void Status()
            {
                updateDealerHandValue();
                std::cout << "Dealer: CPU" << "\t\tHand Value: " << handValue << "\tCards in hand: " << numOfCardsDealt << "\t";
                for (int i = 0; i < numOfCardsDealt; i++) { std::cout << hand[i].name << " of " << hand[i].suit << "\t  "; }
                std::cout << std::endl;
            };
    };

    //Deck
    std::vector<card> deck;
    card ace_D("Ace", "Diamonds", 1);
    card ace_H("Ace", "Hearts", 1);
    card ace_C("Ace", "Clubs", 1);
    card ace_S("Ace", "Spades", 1);
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
    /*
    for (int i = 0; i < deck.size()-1; i++)
    {
        if (temp.empty())
        {
            temp.push_back(deck[i]);
        }
        else
        {
            if (temp[i-1].order_num > deck[i].order_num)
            {
                temp.push_back(temp[i-1]);
                temp[i-1] = deck[i];
            }
            else 
            {
                temp.push_back(deck[i]);
            }
        }
    }*/
        //std::cout << i.order_num << std::endl;
        
    for (int i = 0; i < deck.size() - 1; i++)
    {
        //std::cout << temp[i].order_num << temp[i].name << " of " << temp[i].suit << std::endl;
        //std::cout << "DECK: " << deck[i].name << " of " << deck[i].suit << std::endl;
        shoe.push(deck[i]);
    }

    //void startGame();
    
    int dealCards = 2;
    Dealer dealer;
    Player player;

    dealer.Status();
    player.Status();

    std::cout << "What is the player's name?";
    std::cin >> player.name;

    dealer.Status();
    player.Status();
    
    

        if (!shoe.empty())
        {
            for (int i = 0; i < dealCards; i++)
            {                
                player.hand.push_back(shoe.front());
                shoe.pop();
                dealer.hand.push_back(shoe.front());
                shoe.pop();
            }
        };

        dealer.Status();
        player.Status();

}


    
   


    /* TODO - now have que full of cards 
     * need to create player and dealer with some state (commence play, how many cards in hand to end deal?)    
     * deal function - one card to each player and dealer before dealing second card
     * sum function - sums total value - shown to player, dealers hidden
     * win: player wins if 21 and dealer is less, dealer uncovers 21 if they are dealt it on first two cards (natural - 10 valued card plus ace)
     * lose: either player or dealer exceeds 21
     * dealer restrictions: can not take another card if at 17 or greater
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
