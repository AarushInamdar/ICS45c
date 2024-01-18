#include <iostream>
using namespace std;

double knots_to_miles_per_minute(int knot) {
	double res =(knot*6076)/(double(5280)*double(60));
	return res;
}

