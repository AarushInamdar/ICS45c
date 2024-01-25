#include "coins.hpp"
#include <iostream>

using namespace std;

Coins::Coins(int q, int d, int n, int p)
	: quarters(q), dimes(d), nickels(n), pennies(p){}


Coins :: ostream & operator << (ostream &out, const Coins& coin_count) {
	out << coin_count.q << " quarters, " << coin_count.d << " dimes, " << coin_count.n << " nickels, " << coin_count.p << " pennies ";

	return out;
}

void Coins :: deposit_coins(Coins& coins) {
	Coins.quarters += coins.quarters;
	Coins.dimes += coins.dimes;
	Coins.nickels += coins.nickels;
	Coins.pennies += coins.pennies;

	coins.quarters = coins.dimes = coins.nickels = coins.pennies = 0;
	
}

bool Coins :: has_exact_change_for_coins(const Coins& coins) const {
	transaction_amount = coins.quarters*CENTS_PER_QUARTER + coins.dimes*CENTS_PER_DIME + coins.nickels*CENTS_PER_NICKEL + coins.pennies;

	remaining_value = transaction_amount % Coins.quarters;
	remaining_value = remaining_value % Coins.dimes;
	remaining_value = remaining_value % Coins.nickels;
	remaining_value = remaining_value % Coins.pennies;

	return remaining_value == 0;


}

Coins Coins ::  extract_exact_change(const Coins& coins) const; {
	if has_exact_change_for_coins(coins) {
	remaining_value = coins.quarters*CENTS_PER_QUARTER + coins.dimes*CENTS_PER_DIME + coins.nickels*CENTS_PER_NICKEL + coins.pennies;
	

}

int Coins :: total_value_in_cents() const {
	result  = coins.quarters*CENTS_PER_QUARTER + coins.dimes*CENTS_PER_DIME + coins.nickels*CENTS_PER_NICKEL + coins.pennies;
	return result;
}

void Coins :: print(std::ostream& out) const {
	cout << coins.quarters << " quarters, " << coins.dimes << " dimes, " << coins.nickels << " nickels, " << coins.pennies << " pennies";


}

bool Coins :: operator==(const Coins& other) const=default {
	return quarters==coins.quarters && dimes==coins.dimes && nickels == coins.nickels && pennies == coins.pennies;
}

Coins coins_required_for_cents(int amount_in_cents) {
	

}

void print_cents(int cents, std::ostream& out) {
	
}

Coins ask_for_cents(std::istream& in, std::ostream& out) {

}

void coins_menu(std:: istream& in, std::ostream& out) {

}


