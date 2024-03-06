#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "process_numbers.hpp"



void split_odd_even(std::istream& numbers, std::ostream& odds, std::ostream& evens) {

	std::vector<int> allNumbers{std::istream_iterator<int>(numbers), std::istream_iterator<int>()};

	std::sort(allNumbers.begin(), allNumbers.end());

	std::copy_if(allNumbers.begin(), allNumbers.end(), std::ostream_iterator<int>(odds, " "), [](int n){return n%2!=0; });
	odds << '\n';
	
	std::copy_if(allNumbers.begin(), allNumbers.end(), std::ostream_iterator<int>(evens, "\n"), [](int n){return n%2==0; });
}
