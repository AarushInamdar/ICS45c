#include <iostream>
#include "string.hpp"

//notes to get the rest of the points: 1. fix append, 2. fix index, 3. fix move, 4. free memory wherever needed after all that 

// constructs this string from a C string, defaults to empty string
 String::String(const char *s) {
	head = list::from_string(s);
}

// construct this string as a copy of string s
String::String(const String &s) {
	head = list::copy(s.head);
}

// construct this string by moving from string s MOVE
String::String(String &&s) {
	list::free(head);
	head = s.head;
}

// swap this string with s
void String::swap(String &s) {
	list::Node* temp = s.head;
	s.head = head;
	head = temp;
}

// assignment operator from one string, s, to this string
String &String::operator=(const String &s) {
	if (list::compare(head, s.head) != 0){
		list::free(head);
		head = list::copy(s.head);
	}
	return *this;
}

// assign to this string by moving
String &String::operator=(String &&s) {
	if (head != s.head) {
		list::free(head);
		head = s.head;
		s.head = nullptr;
	}
	return *this;
}

// check if we can index at position i in this string
bool String::in_bounds(int index) const {
	return (index < list::length(head)) ? true : false;
}

// allow const indexing
char String::operator[](int index) const {
	if (in_bounds(index)) {
		return list::nth(head,index)->data;
	} else {
		return *"ERROR";
	}
	//return (in_bounds(index)) ? list::nth(head, index)->data : '\0';
}

// returns the logical length of this string (# of chars up to '\0')
int String::size() const {
	return list::length(this->head);
}

// returns a reversal of this string, does not modify this string
String String::reverse() const {
	String s;
	s.head = list::reverse(this->head);
	return s;
}

// returns index into this string for first occurrence of c
int String::indexOf(char c) const {
	return list::index(this->head, list::find_char(this->head, c));
}

// returns index into this string for first occurrence of s
int String::indexOf(const String &s) const {
	return list::index(this->head, list::find_list(this->head,s.head));
}

// compare this string with another string by equality
// note: != is auto-generated since C++20
bool String::operator==(const String &s) const {
	return list::compare(this->head, s.head) == 0;	
}

// C++20 way of defining all comparisons at once
std::strong_ordering String::operator<=>(const String &s) const {
	int myVal = list::compare(this->head, s.head);
	if (myVal == 0) {
		return std::strong_ordering::equal;
	} else if (myVal >0) {
		return std::strong_ordering::greater;
	} else {
		return std::strong_ordering::less;
	}
}

// concatenate this and s to form a return string
String String::operator+(const String &s) const{
	String a;
	a.head = list::append(this->head, s.head);
	list::free(head);
	return a;
}

// concatenate s onto the end of this string
String &String::operator+=(const String &s) {
	head = list::append(this->head, s.head);
	return *this;
}
void String::print(std::ostream &out) const {
	list::print(out, head);
}

    // read next word into this string
    // hint: use operator >> to read from in into a temporary buffer
void String::read(std::istream &in) {
	char myIn[9999];
	in >> myIn;
	list::free(head);
	head = list::from_string(myIn);
}

// print this string, hint: use operator << to send buf to out

String::~String() {
	free(this->head);
}

std::ostream &operator<<(std::ostream &out, const String &s) {
	s.print(out);
	return out;
}

std::istream &operator>>(std::istream &in, String &s) {
	s.read(in);
	return in;
}

