#include <iostream>
using namespace std;
#include "string.hpp"

String::String(const char *s) {
	
}

String::String(const String &s) {
	
}


void String::swap(String &s) {
	
}

String &String::operator=(String s) {
	
}

String &String::operator[](int index) {
	
}

const char &String::operator[](int index) const {
	
}

int String::size() const {
	
}

String String::reverse() const {
	
}

int String::indexOf(char c) const {
	
}

bool String::operator==(String s) const {
	
}

bool String::operator!=(String s) const {
	
}
bool String::operator>(String s) const {
	
}

bool String::operator<(String s) const {
	
}

bool String::operator<=(String s) const {
	
}


bool String::operator>=(String s) const {
	
}


String String::operator+(String s) const {
	
}


String &String::operator+=(String s) {
	
}


void String::print(std::ostream &out) const {
	out << buf;
}


void String::read(std::istream &in) {
	in buf;
}


char String::strdup(const char *src) {
	
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
	
	for (s=0; src[s] != '\0' && s < n; ++s) {
		dest[i] = src[s];
		++i;
		}
	dest[i] = '\0';
	return dest;
