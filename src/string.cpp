#include <iostream>
using namespace std;
#include "string.hpp"


//current things to address: dynamic size of buf (prevents SEGV);  operator >>(prevents Stack overflow); strdup(); strcat(); strncat(); strcmp(); strncmp();
String::String(const char *s) {
	/*char *buf = new char[strlen(s)]; //find a way to allot the exact space without causing a SEGV like u are
	if (s) {
		strcpy(buf, s);
	}*/

	if (s==nullptr || s[0]=='\0'){
		buf = new char[1];
		buf[0] = '\0';
	} else {
		char *buf = strdup(s);
	}
}

String::String(const String &s) {
	char *buf = strdup(s.buf);	
}

String::String(String &&s) : buf(s.buf) {
	s.buf = nullptr;
}

String::String(int length) : buf(new char[length+1]) {
	buf[0] = '\0';
}

void String::swap(String &s) {
	std::swap(buf, s.buf);	
}

String &String::operator=(const String &s) {
	if (this != &s) {
	delete[] buf;
	buf = strdup(s.buf);
	
	}
	return *this;
	
}

String &String::operator=(String &&s) {
	if (this != &s) {
		delete[] buf;
		buf = s.buf;
		s.buf = nullptr;
	}
	return *this;
}
	
char &String::operator[](int index) {
	if (in_bounds(index)) {
		return buf[index];
	} else {
		cout << "ERROR: Index out of bounds" << endl;
		return buf[0];
	}
}

const char &String::operator[](int index) const {
	if (in_bounds(index)) {
		return buf[index];
	} else {
		cout << "ERROR: Index out of bounds" << endl;
		return buf[0];
	}
}

int String::size() const {
	return strlen(buf);
}

String String::reverse() const {
	char *dest;
	reverse_cpy(dest, buf);
	return String(dest);
}

int String::indexOf(char c) const {
	const char *p = strchr(buf, c);
	if (p!=nullptr){
		return p-buf;
	} else {
		return -1;
	}
}

//rework this function
int String::indexOf(const String s) const {
	const char *p = strstr(buf, s.buf);
	if (p!=nullptr){
		return p-buf;
	} else {
		return -1;
	}
}


bool String::operator==(String s) const {
	return (strcmp(buf, s.buf) == 0) ? true : false;
}

bool String::operator!=(String s) const {
	return (strcmp(buf, s.buf) !=  0) ? true : false;

}

bool String::operator>(String s) const {
	return (strcmp(buf, s.buf) > 0) ? true : false;
}

bool String::operator<(String s) const {
	return (strcmp(buf, s.buf) < 0) ? true : false;

}

bool String::operator<=(String s) const {
	return (strcmp(buf, s.buf) <= 0) ? true : false;
}


bool String::operator>=(String s) const {
	return (strcmp(buf, s.buf) >=  0) ? true : false;
}


String String::operator+(String s) const { //probably have to use "new" here or in its helper functions;
	int new_length = strlen(s.buf) + strlen(buf);
	char *R = new char[new_length+1];
	strcpy(R, buf);
	strcat(R, s.buf);
	String result(R);
	delete[] R;

	return result;
}


String &String::operator+=(String s) {
	int new_length = strlen(buf) + strlen(s.buf);
	char *replacement = new char[new_length+1];

	strcpy(replacement, buf);
	strcat(replacement, s.buf);

	delete[] buf;
	buf = replacement;
	return *this;
}


void String::print(std::ostream &out) const {
	out << buf;
}

//potential cause of Stack overflow issue
void String::read(std::istream &in) {
	//copy private buf to a stack variable and in>> that variable
	char currentVar[2048];

	in >> currentVar;

	delete[] buf;
	buf = strdup(currentVar);
}


char *String::strdup(const char *src) {
	int length = strlen(src) + 1;
	char *res = new char[length]; //how to better assign the proper length;

	strcpy(res, src);

	return res;
}

int String::strlen(const char *s) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}
	
char *String::strcpy(char *dest, const char *src) {

	int i = 0;
	for (i=0; src[i]!='\0'; ++i) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	
	return dest;

}

char *String::strncpy(char *dest, const char *src, int n) {
	int i = 0;
	for (i=0; i <  n && src[i] != '\0'; ++i) {
		dest[i] = src[i];
		}
	dest[i] = '\0';
	
	return dest;
}


char *String::strcat(char *dest, const char*src) {
	int i = strlen(dest);
	int s = 0;
	
	for (s=0; src[s] != '\0'; ++s) {
		dest[i] = src[s];
		++i;
		}
	dest[i] = '\0';
	return dest;
	
}

char *String::strncat(char *dest, const char*src, int n) {
	int i = strlen(dest);
	int s = 0;
	
	for (s=0; src[s] != '\0' && s < n; ++s) {
		dest[i] = src[s];
		++i;
		}
	dest[i] = '\0';
	return dest;
}

int String::strcmp(const char *left, const char *right) {
	int i = 0;
	for (i=0;(left[i] != '\0' || right[i] != '\0'); ++i) {
		if (left[i] != right[i]) {
			int res = (left[i]-right[i]);
			return res;
		}
	}
	return 0;
}

int String::strncmp(const char *left, const char *right, int n) {
	int i = 0;
	while (left[i] == right[i] && left[i] != '\0' && right[i] != '\0' && i < n) {
		i++;
	}
	if (i==n) return 0;
	return left[i]-right[i];
}

void String::reverse_cpy(char *dest, const char *src) {
	int i = 0;
	int start = String::strlen(src)-1;

	for (start = String::strlen(src)-1; start >= 0; start--) {
		dest[i] = src[start];
		i++;
		}
	dest[i] = '\0';
}

const char *String::strchr(const char *str, char c) {
		
		if (str == nullptr) {
			return nullptr;
		}

		do {
			if (*str ==c) {
				return str;
			}
		} while (*str++);

		return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle) {
	

	if (!needle || !*needle) {
		return haystack;
	}

	while (*haystack) {
		const char *h = haystack;
		const char *n = needle;

		while (*n && *h && *h == *n) {
			++h;
			++n;
		}
		if (!*n) {
			return haystack;
		}

		++haystack;
	}
	return nullptr;
}

String::~String() {
	delete[] buf;
}


std::ostream &operator<<(std::ostream &out, String s) {
	s.print(out);
	return out;
}
//potential cause of Stack overflow issue
std::istream &operator>>(std::istream &in, String &s) {
	s.read(in);
	return in;
}


