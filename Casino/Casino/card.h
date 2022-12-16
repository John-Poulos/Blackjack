#pragma once
#include <iostream>
#include <vector>
#include <queue>

//create prototype for a playing card
class card
{
public:
    std::string name;
    std::string suit;
    std::int16_t value;
    std::int16_t order_num;     //used for randomizing position of card in deck

    card(std::string p_name, std::string p_suit, std::int16_t p_value)
    {
        name = p_name;
        suit = p_suit;
        value = p_value;
        order_num = random_value();
    }

    int random_value();

    //overload the less than comparator to allow sort() to work
    bool operator<(const card& rhs);

    //card constructor
  


};


