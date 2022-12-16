#include "card.h"

int card::random_value() 
{
	int random = rand();
	return random;
}

bool card::operator<(const card& rhs)
{
	return (order_num < rhs.order_num);
}