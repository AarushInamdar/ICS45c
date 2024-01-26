#include <iostream>
#include "coins.hpp"

using namespace std;

Coins::Coins(int q, int d, int n, int p) : quarters(q), dimes(d), nickels(n), pennies(p) {}



void Coins::deposit_coins(Coins& coins) {
	quarters += coins.quarters;
	dimes += coins.dimes;
	nickels += coins.nickels;
	pennies += coins.pennies;

	coins.quarters = coins.dimes = coins.nickels = coins.pennies = 0;
	
}

bool Coins::has_exact_change_for_coins(const Coins& coins) const {
	return quarters >= coins.quarters && dimes >= coins.dimes && nickels >= coins.nickels && pennies >= coins.pennies;
}

Coins Coins::extract_exact_change(const Coins& coins) const {
	if (!has_exact_change_for_coins(coins)){
		return Coins(0,0,0,0);
	}

	int q, d, n, p;
	q = quarters - coins.quarters;
	d = dimes - coins.dimes;
	n = nickels - coins.nickels;
	p = pennies - coins.pennies;

	return Coins(q,d,n,p);	

}

int Coins::total_value_in_cents() const {
	int result  = quarters*CENTS_PER_QUARTER + dimes*CENTS_PER_DIME + nickels*CENTS_PER_NICKEL + pennies;
	return result;
}

void Coins::print(std::ostream& out) const {
	out << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << pennies << " pennies";

}


ostream& operator<<(ostream& out, const Coins& coin_count) {
	coin_count.print(out);	
	return out;
}



Coins coins_required_for_cents(int amount_in_cents) {
	

	int q, d, n, p;
	int remaining_amount = amount_in_cents;
	
	q = remaining_amount / CENTS_PER_QUARTER;
	remaining_amount = remaining_amount%(q*CENTS_PER_QUARTER);
	

	d = remaining_amount / CENTS_PER_DIME;
	remaining_amount = remaining_amount%(d*CENTS_PER_DIME);
	
	n = remaining_amount / CENTS_PER_NICKEL;
	remaining_amount = remaining_amount%(n*CENTS_PER_NICKEL);
	
	p = remaining_amount;
	remaining_amount = 0 ;
	
	return Coins(q,d,n,p);

	}
void print_cents(int cents, std::ostream& out) {
	int dollars = cents / 100;
	int remainingCents = cents%100;

	out << "$" << dollars << ".";
	if (remainingCents < 10){
		out << '0';
	}
	out << remainingCents;
	out.flush();
	
}

Coins ask_for_cents(std::istream& in, std::ostream& out) {
	int q, d, n, p;

	out << "Quarters? ";
	in >> q;
	
	out << "\nDimes? ";
	in >> d;
	
	out << "\nNickels? ";
	in >> n;

	out << "\nPennies? ";
	in >> p;

	return Coins(q, d, n, p);

}

void coins_menu(std:: istream& in, std::ostream& out) {
	bool cont = true;
	Coins bank(0,0,0,0);

	while(cont) {
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

		

		if (option == 1) {
			
			Coins current_coins = ask_for_cents(in, out);
			bank.deposit_coins(current_coins);

		out << "\nThank you!" << endl;
		out << "\n";

		
		} else if (option == 2) {
			Coins remove_coin = ask_for_cents(in, out);
			if (bank.has_exact_change_for_coins(remove_coin)) {
				
				
				bank = bank.extract_exact_change(remove_coin);
				out << "\nThank you!" << endl;
				out << "\n";
			} else {
				out << "ERROR: Insufficient Funds\n" << endl;
			}			
		} else if (option == 3) {
			int current_value = bank.total_value_in_cents();

			print_cents(current_value, out);
			
			out << "\n\nThank You!\n" <<endl;
		
		} else if (option == 4) {
			cont = false;
		
		} else {
			out << "ERROR: Invalid Command" << endl;
			out << "\n";
		}
	}
}

