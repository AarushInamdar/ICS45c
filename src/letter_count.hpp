int char_to_index(char ch)
{
if (ch >= 'A' && ch <= 'Z'){
	return ch-'A';

} else if (ch >='a' && ch <='z'){
	return ch-'a';
}
return -1;
}

char index_to_char(int i)
{
return 'A'+i;
}

void count(string str, int counts[])
{
for (char c : str){
	int index = char_to_index(c);
	if (index != -1){
		counts[index]++;
	}
}
}

void print_counts(int counts[], int length)
{

for (int i = 0; i <length; i++) {
	std::cout << index_to_char(i) << " " << counts[i] << '\n';
	}
}


