#include <iostream>
using namespace std;

#include "string.hpp"

String::String(const char *s) {
	if (s && strlen(s)<MAXLEN) {
		strncpy(buf,s,MAXLEN-1);
	} else {
		cout << "ERROR: String Capacity Exceeded" <<endl;
		strncpy(buf,s,MAXLEN-1);
	}	
}

String::String(const String &s) {
	strncpy(buf, s.buf, MAXLEN-1);
}

String &String::operator=(const String &s) {
	if (this != &s) {
		strncpy(buf, s.buf, MAXLEN);
		}
		buf[MAXLEN-1];
		return *this;
}

char &String::operator[](int index) {
	return (index < strlen(buf)) ? buf[index] : buf[0];
}

int String::strlen(const char *s) {
	int i = 0;
	for (i=0; s[i] != '\0'; ++i) {
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
	
	while (src[s]!='\0' && s < n) {
		dest[i] = src[s];
		++i;
		++s;
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
	for (i=0; i < n; ++i) {
			if (left[i] == '\0' || right[i] == '\0') {
			int res = (left[i]-right[i]);
			return res;
			} else if (left[i] != right[i]) {
			int res = (left[i]-right[i]);
			return res;
			}

		}	
	return 0;
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

int String::size() const {
	int value = strlen(buf);
	return value;
}

String String::reverse() const {
	char* myString;
	reverse_cpy(myString, buf);
	return String(myString);
}

int String::indexOf(char s) const {
	const char *p = strchr(buf, s);
	if (p!=nullptr){
		return p-buf;
	} else {
		return -1;
	}
}

int String::indexOf(const String &s) const {
	const char *p = strstr(buf, s.buf);
	if (p!=nullptr){
		return p-buf;
	} else {
		return -1;
	}
}

bool String::operator==(const String &s) const {
	return (strcmp(buf, s.buf) == 0) ? true : false;
}

bool String::operator!=(const String &s) const{
	return (strcmp(buf,s.buf) != 0) ? true : false;
}

bool String::operator>(const String &s) const{
	return (strcmp(buf, s.buf) > 0) ? true : false;
}

bool String::operator<(const String &s) const{
	return (strcmp(buf,s.buf) < 0) ? true : false;
}

bool String::operator<=(const String &s) const{
	return (strcmp(buf, s.buf) <= 0) ? true : false;
}

bool String::operator>=(const String &s) const{
	return (strcmp(buf,s.buf) >= 0) ? true : false;
}


String String::operator+(const String &s) const {
	String R;
	strcpy(R.buf, buf);
	strcat(R.buf, s.buf);
	if (strlen(R.buf) > MAXLEN) {
		cout << "ERROR: String Capacity Exceeded" << endl;
		R.buf[MAXLEN-1] = '\0';
		}
	return R;
}

String &String::operator+=(const String &s){
	strncat(buf, s.buf, MAXLEN-1);

	if (strlen(buf) > MAXLEN) {
		cout << "ERROR: String Capacity Exceeded" << endl;
		buf[1024] = '\0';
		}
	return *this;
}

void String::print(std::ostream &out) const {
	out << buf;
}

void String::read(std::istream &in) {
	in >> buf;
}


String::~String() {
	cout << "String <buf> is destructing" << endl;
}

std::ostream &operator<<(std::ostream &out, const String &s) {
	s.print(out);
	return out;
}

std::istream &operator>>(std::istream &in, String &s) {
	s.read(in);
	return in;
}



