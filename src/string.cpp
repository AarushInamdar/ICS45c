#include <iostream>
using namespace std;

#include "string.hpp"

String::String(const char *s) {
	if (s && strlen(s)<MAXLEN) {
		strncpy(buf,s,MAXLEN-1);
	} else {
		buf[0] = '\0';
	}	
}

String::String(const String &s) {
	strncpy(buf, s.buf, MAXLEN-1);

}

String &String::operator=(const String &s) {
	String value = String(s);
	return value;
}

char &String::operator[](int index) {
	char myChar = buf[index];
	return myChar;
}

int String::strlen(const char *s) {
	int i = 0;
	for (i=0; s[i] != '\0' && i < MAXLEN; ++i) {
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

	for (s=0; src[s]!='\0' && i < n; ++s) {
		dest[i] = src[s];
		++i;
	}
	dest[i] = '\0';
	return dest;
}

int strcmp(const char *left, const char *right) {
	int i = 0;
	for (i=0;(left[i] != '\0' && right[i] != '\0'); ++i) {
		if (left[i] != right[i]) {
			int res = (left[i] > right[i]) ? 1 : -1;
			return res;
		}
	}
	return 0;
}

int String::strncmp(const char *left, const char *right, int n) {
	int i = 0;
	for (i=0;left[i] != '\0' && right[i] != '\0' && i < n; ++i) {
		if (left[i] != right[i]) {
			int res = (left[i] > right[i]) ? 1 : -1;
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
		int len = strlen(str);

		for (int i=0;(str[i] != '\0' && i < len); ++i) {
			if (str[i]==c) {
				return c;
			}
		return nullptr;
	}



const char *String::strstr(const char *haystack, const char *needle) {
	int len = strlen(needle);
	for (char *p = haystack; (p=strchr(p,needle[0]); ++p) {
		if(strncmp(p,needle,len) == 0) {
			return p;
		}
	return nullptr;
}

int String::size() {
	int value = strlen(buf);
	return value;
}

String String::reverse() {
	char* myString;
	reverse_cpy(myString, buf);
	return String(myString);
}

int String::indexOf(const String &s) {
	
}

bool String::operator==(const String &s) const {
	
}

bool String::operator!=(const String &s) const{
	
}

bool String::operator>(const String &s) const{
	
}

bool String::operator<(const String &s) const{
	
}

bool String::operator<=(const String &s) const{
	
}

bool String::operator>=(const String &s) const{
	
}


String String::operator+(const String &s) {
	
}

String &String::operator+=(const String &s){
	
}

void String::print(std::ostream &out) const {
	
}

void String::read(std::istream &in) {
	
}


String::~String() {
	cout << "String <buf> is destructing" << endl;
}

std::ostream &operator<<(std::ostream &out, const String &s) {
	
}

std::istream &operator>>(std::istream &in, String &s) {
	
}



