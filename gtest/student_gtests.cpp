#include <gtest/gtest.h>

#include "string.hpp"

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
}

TEST(StringFunction, strcmp) {
	char result[10];
    char man[10];
	String::strcpy(result, "foo");
	
	String::strcpy(man, "foa");
	int value = String::strcmp(result, man); 
	EXPECT_EQ(value, 1);

	String::strcpy(man, "foo");
	value = String::strcmp(result, man); 
	EXPECT_EQ(value, 0);

	String::strcpy(man, "foy");
	value = String::strcmp(result, man); 
	EXPECT_EQ(value, -1);
}

TEST(StringFunction, strncmp) {
   
}

TEST(StringFunction, reverse_cpy) {
    char result[10];
    char man[10];


	String::strcpy(result, "foo");
	String::reverse_cpy(man,result);
   	EXPECT_STREQ(man, "oof");
	
	String::strcpy(result, "a");
    String::reverse_cpy(man,result);
    EXPECT_STREQ(result, "a");
	
	String::strcpy(result, "");
    String::reverse_cpy(man, result);
    EXPECT_STREQ(result, "");

}

TEST(StringFunction, strchr) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(false);
}
