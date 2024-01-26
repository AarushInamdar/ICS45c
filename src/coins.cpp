#include <iostream>
#include "coins.hpp"

using namespace std;

Coins::Coins(int q, int d, int n, int p){
	quarters = q;
	dimes = d;
	nickels = n;
	pennies = p;
}


ostream& operator<<(ostream& out, const Coins& coin_count) {
	out << coin_count.quarters << " quarters, " << coin_count.dimes << " dimes, " << coin_count.nickels << " nickels, " << coin_count.pennies << " pennies ";

	return out;
}

void Coins :: deposit_coins(Coins& coins) {
	this->quarters += coins.quarters;
	this->dimes += coins.dimes;
	this->nickels += coins.nickels;
	this->pennies += coins.pennies;

	coins.quarters = coins.dimes = coins.nickels = coins.pennies = 0;
	
}

bool Coins :: has_exact_change_for_coins(const Coins& coins) const {
	int transaction_amount, remaining_value;

	transaction_amount = coins.quarters*CENTS_PER_QUARTER + coins.dimes*CENTS_PER_DIME + coins.nickels*CENTS_PER_NICKEL + coins.pennies;

	remaining_value = transaction_amount % this->quarters;
	remaining_value = remaining_value % this->dimes;
	remaining_value = remaining_value % this->nickels;
	remaining_value = remaining_value % this->pennies;

	return remaining_value == 0;


}

Coins Coins::extract_exact_change(const Coins& coins) const {
	Coin result;

	result.quarters = this->quarters - coins.quarters;
	result.dimes = this->dimes - coins.dimes;
	result.nickels = this->nickels - coins.nickels;
	result.pennies = this->pennies - coins.pennies;

	return result;	

}

int Coins :: total_value_in_cents() const {
	result  = this->quarters*CENTS_PER_QUARTER + this->dimes*CENTS_PER_DIME + this->nickels*CENTS_PER_NICKEL + this->pennies;
	return result;
}

void Coins :: print(std::ostream& out) const {
	cout << this->quarters << " quarters, " << this->dimes << " dimes, " << this->nickels << " nickels, " << this->pennies << " pennies";


}

bool Coins :: operator==(const Coins& other) const=default {
	return this->quarters==other.quarters && this->dimes==other.dimes && this->nickels == other.nickels && this->pennies == other.pennies;
}

Coins coins_required_for_cents(int amount_in_cents) {
	Coins required(0,0,0,0);

	int quarters, dimes, nickels, pennies;
	int remaining_amount = amount_in_cents;
	
	required.quarters += remaining_amount / CENTS_PER_QUARTER;
	remaining_amount = remaining_amount%(required.quarters*CENTS_PER_QUARTER);
	

	required.dimes += remaining_amount / CENTS_PER_DIME;
	remaining_amount = remaining_amount%(required.dimes*CENTS_PER_DIME);
	
	required.nickels += remaining_amount / CENTS_PER_NICKEL;
	remaining_amount = remaining_amount%(required.nickels*CENTS_PER_NICKEL);
	
	required.pennies += remaining_amount;
	remaining_amount = 0 ;

	return required;

	}

}

void print_cents(int cents, std::ostream& out) {
	double value = cents/double(100.0);

	out << "$" << value << endl;

	
}

Coins ask_for_cents(std::istream& in, std::ostream& out) {
	int q, d, n, p;

	out << "Quarters? ";
	in >> q;
	out << endl;
	
	out << "Dimes? ";
	in >> d;
	out << endl;
	
	out << "Nickels? ";
	in >> n;
	out << endl;

	out << "Pennies? ";
	in >> p;
	out << endl;

	Coins coinn(q, d, n, p);

	return coinn;

}

void coins_menu(std:: istream& in, std::ostream& out) {
	bool cont = true;
	while(cont);
	{
	out << "Coins Menu" << endl;
	out << "\n";
	
	out << "1. Deposit Change" << endl;
	out << "2. Extract Change" << endl;
	out << "3. Print Balance" << endl;
	out << "4. Exit" << endl;
	out << "\n";
	out << "User input: ";
	
	int option;
	in >> option;

	out << "\nThank you!" << endl;
	out << "\n";


	if (option == 1) {
		Coin current_coins;
		current_coins = ask_for_cents(in, out);
	
	} else if (option == 2) {
		Coin remove_coin;
		remove_coin = ask_for_cents(in, out);
		extract_exact_change(remove_coin);
		if(this->quarters < 0 || this->dimes < 0 || this->nickels < 0 || this->pennies < 0){
			out << "ERROR: Insufficient Funds" << endl;
			out << "\n";
			deposit_coins(remove_coin);
		}
	
	} else if (option == 3) {
		int current_value = total_value_in_cents();

		out << print_cents(current_value, out) << endl;
		out << "\n" << endl;
		out << "Thank You!" <<endl;
	
	} else if (option == 4) {
		cont = false;
	
	} else {
		out << "ERROR: Invalid Command" << endl;
		out << "\n";
	}
	}
		
}

