#include <iostream>
using namespace std;
#include "convert_knots.hpp"

int main() {
	int knots = 0;
	cout << "Enter integer speed in knots" << endl;
	cin >> knots;
	cout << "Speed in miles per minute" << endl
		 << knots_to_miles_per_minute(knots)
		 << endl;
	return 0;
}
