
#include <iostream>
#include "Value.h"
#include "Suit.h"

class Card
{

private:
	
	Suit::Suits suit_T;

	Value::Values value_T;

public: 

	Card(Suit::Suits suit,Value::Values value) {
		value_T = value;
		suit_T = suit;
	}

	std::string toString() {
		return suit_T + " - " + value_T;
	}

	Value::Values getValue() {
		return value_T;
	}

	Suit::Suits getSuit() {
		return suit_T;
	}
};

