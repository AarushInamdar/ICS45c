#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"


TEST(StringFunction, strdup) {
    char src[] = "World";
	char *p = src;
	EXPECT_STREQ(strdup(p),p);
	EXPECT_NE(strdup(p), p);

	char myVar[] = "Where is my Water?";
	char *pointer = myVar;
	EXPECT_STREQ(strdup(pointer), pointer);
	EXPECT_NE(strdup(pointer), pointer);
	std::cout << "Pointer variable: " <<  pointer << std::endl;

}

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("crazy"), 5);
	EXPECT_EQ(String::strlen("a"),1);
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
    int MAXLEN = 1024;
	char result[] = "man";
	EXPECT_STREQ(String::strncpy(result, "foo", MAXLEN), "foo");
	EXPECT_STREQ(String::strncpy(result, "olaf", MAXLEN), "olaf");

}

TEST(StringFunction, strcat) {
    char src[] = "World";
	char dest[] = "Hello";

	EXPECT_STREQ(String::strcat(dest, src), "HelloWorld");
}

TEST(StringFunction, strncat) {
    int MAXLEN = 1024;
	char src[] = "World";
	char dest[] = "Hello";

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
	int MAXLEN = 1024;


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










































