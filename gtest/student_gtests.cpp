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

	EXPECT_STREQ(String::strncat(dest, src, 3), "HelloWorldWor");

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
	int value = String::strcmp(result, man); 
	EXPECT_EQ(value, 14);

	String::strncpy(man, "foo", MAXLEN);
	value = String::strcmp(result, man); 
	EXPECT_EQ(value, 0);

	String::strncpy(man, "foy", MAXLEN);
	value = String::strcmp(result, man); 
	EXPECT_EQ(value, -10);

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
    const char test_string[20] = "Hello, World!";
	char char_to_find = 'W';

	const char* result = String::strchr(test_string, char_to_find);

	ASSERT_NE(result-test_string, 0);
	EXPECT_EQ(result-test_string, 7);

	result = String::strchr(test_string, 'X');

	EXPECT_EQ(result, nullptr);
	
	result = String::strchr(test_string, '\0');
	ASSERT_NE(result-test_string,1);
	EXPECT_EQ(result-test_string, 13);

}

TEST(StringFunction, strstr) {
	const char haystack[20] = "Hello, World!";
	const char needle[20] = "Wor";

	const char* result = String::strstr(haystack,needle);
	ASSERT_NE(result-haystack,0);
	EXPECT_EQ(result-haystack,7);

	result = String::strstr(haystack,"needle");
	EXPECT_EQ(result,nullptr);

	result = String::strstr(haystack,"");
	ASSERT_NE(result-haystack,13);
	EXPECT_EQ(result-haystack,0);

}
