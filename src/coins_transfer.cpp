#include <iostream>
using namespace std;
#include "coins.hpp"

int main() {
	Coins piggyBank(50, 50, 50, 50);
	Coins pocket(8, 3, 6, 8);
	int chips_cost = 149;

	cout << "Initial piggy bank: " << piggyBank << endl;
	cout << "Initial pocket: " << pocket << endl;

	
	Coins needed_coins_for_chips = coins_required_for_cents(chips_cost);
	cout << "Bought chips using pocket" << endl;
	cout << "Chips required the coins: " << needed_coins_for_chips << endl;
	pocket.extract_exact_change(needed_coins_for_chips);
	cout << "Pocket after paying for Chips: " << pocket << endl;

	Coins needed_coins_for_transfer = coins_required_for_cents(405);
	cout << "Transferring money to pocket" << endl;
	cout << "Coins for transfer: : " << needed_coins_for_transfer << endl;
	piggyBank.extract_exact_change(needed_coins_for_transfer);
	pocket.deposit_coins(needed_coins_for_transfer);
	cout << "Pocket: " << pocket << endl;
	cout << "Piggy Bank: " << piggyBank << endl;

	cout << "Piggy Bank Total: ";
	print_cents(piggyBank.total_value_in_cents(), cout);
	cout << endl;

	return 0;
	}
	

