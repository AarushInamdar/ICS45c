#include <iostream>
using namespace std;

constexpr int N_CHARS = ('Z' - 'A' +1);

int main()
{
int counters[N_CHARS]{0};
string line;
while (cin, line){
	count(line, counters);

print_counts(counters, N_CHARS);
return 0;
}


