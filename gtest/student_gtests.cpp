#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"


TEST(StringFunction, strdup) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[MAXLEN];
	EXPECT_STREQ(String::strncpy(result, "foo", MAXLEN), "foo");
	EXPECT_STREQ(String::strncpy(result, "olaf", MAXLEN), "olaf");

}

TEST(StringFunction, strcat) {
    char src[MAXLEN] = "World";
	char dest[MAXLEN] = "Hello";

	EXPECT_STREQ(String::strcat(dest, src), "HelloWorld");
}

TEST(StringFunction, strncat) {
    char src[MAXLEN] = "World";
	char dest[MAXLEN] = "Hello";

	EXPECT_STREQ(String::strncat(dest, src, MAXLEN), "HelloWorld");

	EXPECT_STREQ(String::strncat(dest, src, 3), "HelloWorldWor");

}

TEST(StringFunction, strcmp) {
	char result[10];
    char man[10];
	String::strcpy(result, "foo");
	
	String::strcpy(man, "foa");
	int value = String::strcmp(result, man); 
	EXPECT_EQ(value, 14);
}


TEST(StringFunction, strcmp) {
	char result[10];
    char man[10];
	String::strcpy(result, "foo");
	
	String::strcpy(man, "foa");
	int value = String::strcmp(result, man); 
	EXPECT_EQ(value, 14);

	String::strcpy(man, "foo");
	value = String::strcmp(result, man); 
	EXPECT_EQ(value, 0);

	String::strcpy(man, "foy");
	value = String::strcmp(result, man); 
	EXPECT_EQ(value, -10);
}

TEST(StringFunction, strncmp) {
    char result[10];
    char man[10];
	String::strncpy(result, "foo", MAXLEN);
	
	String::strncpy(man, "foa", MAXLEN);
	int value = String::strncmp(result, man, 4); 
	EXPECT_EQ(value, 14);

	value = String::strncmp(result, man, 2); 
	EXPECT_EQ(value, 0);

	String::strncpy(man, "foy", MAXLEN);
	value = String::strncmp(result, man, 4); 
	EXPECT_EQ(value, -10);


	char test1[10] = "test";
	char right[10] = "testa";

	value = String::strncmp(test1, right, 5); 
	EXPECT_LT(value, 0);

}

TEST(StringFunction, reverse_cpy) {
    char result[10];
    char man[10];


	String::strcpy(result, "foo");
	String::reverse_cpy(man,result);
}












































