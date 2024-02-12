#include <gtest/gtest.h>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;
	
    EXPECT_EQ(foo_list->data, 'f');
    
	// ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    
	ASSERT_NE(foo_list->next, nullptr);
	
    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);
	
    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    
	/*ASSERT_EQ(foo_list->next, nullptr);


	Node* const emptyStringHead = list::from_string("");
	Node* eString = emptyStringHead;

	EXPECT_EQ(eString->data, nullptr);*/
	
	
    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
	
	Node* const head2 = list::from_string("hello");
	EXPECT_EQ(list::length(head2), 5);
	list::free(head2);


	Node* const head3 = list::from_string("");
    EXPECT_EQ(list::length(head3), 0);
    list::free(head3);


}


TEST(ListTests, Compare) {
    EXPECT_EQ(list::compare(list::from_string("hello"), list::from_string("hello")), 0);

	EXPECT_EQ(list::compare(list::from_string("hella"), list::from_string("hellb")), -1);

	EXPECT_EQ(list::compare(list::from_string("helld"), list::from_string("hellb")), 2);

	EXPECT_EQ(list::compare(list::from_string("hella"), list::from_string("hellb"), 4), 0);

	EXPECT_EQ(list::compare(list::from_string("heatd"), list::from_string("heftd"), 3), -5);



}


TEST(ListTests, Copy) {
    Node* const head = list::from_string("foo");
	Node* myNode = list::copy(head);
	
	std::cout << "head: " << std::endl;
	list::print(std::cout, head);
	std::cout<< "\nmyNode: "  << std::endl;
	list::print(std::cout, myNode);
	
	EXPECT_EQ(list::compare(head, myNode), 0);


	
	Node* const extreme  = list::from_string("");
	Node* myExtreme = list::copy(extreme);
	EXPECT_EQ(list::compare(extreme, myExtreme), 0);

}




TEST(ListTests, Append) {
    
	Node* hwa = list::append(list::from_string("hello"), list::from_string("world"));
	Node* hw = list::from_string("helloworld");
	std::cout << "Hwa: " << std::endl;
	list::print(std::cout, hwa);
	std::cout << "Hw: helloworld" << std::endl;


	EXPECT_EQ(list::compare(hwa, hw), 0);



	Node* hwb = list::append(list::from_string("hi"), list::from_string("world"));
	Node* hwo = list::from_string("helloworld");

	EXPECT_NE(list::compare(hwb, hwo), 0);

}

TEST(ListTests, Last) {
    Node* hw = list::from_string("helloworld");
	EXPECT_EQ(list::compare(last(hw), list::from_string("d")),0);
	std::cout << "Function Last: " << std::endl;
	
	list::print(std::cout, last(hw));



	Node* nothing = list::from_string("a");
	EXPECT_EQ(list::compare(last(nothing), nothing), 0);


	Node* hwZ = list::from_string("helloworldZ");
	EXPECT_NE(list::compare(last(hwZ), list::from_string("Zd")),0);

}




TEST(ListTests, Nth) {
    Node* myNode = list::from_string("HelloWorld");
	
	Node* myP = list::nth(myNode, 3);
	EXPECT_EQ(myP->data, 'l');


	myP = list::nth(myNode, 6);
	EXPECT_EQ(myP->data, 'W');


	myP = list::nth(myNode, 1);
	EXPECT_EQ(myP->data, 'H');

}

TEST(ListTests, Index) {
    Node* longNode = list::from_string("HelloWorld");
	Node* shortNode = list::from_string("World");

	EXPECT_EQ(index(longNode, shortNode), 5);

	shortNode = list::from_string("d");
	EXPECT_EQ(index(longNode, shortNode), 9);

	shortNode = list::from_string("el");
	EXPECT_EQ(index(longNode, shortNode), 1);
}


TEST(ListTests, FindChar) {
    Node* longNode = list::from_string("HelloWorld");
	
	char myChar = 'W';
	EXPECT_EQ(list::compare(list::find_char(longNode, myChar), list::from_string("World")), 0);

	myChar = 'r';
	EXPECT_EQ(list::compare(list::find_char(longNode, myChar), list::from_string("rld")), 0);
	EXPECT_NE(list::compare(list::find_char(longNode, myChar), list::from_string("World")), 0);

	myChar = 'z';
	EXPECT_EQ(list::find_char(longNode, myChar), nullptr);


}

TEST(ListTests, FindList) {
    Node* longNode = list::from_string("HelloWorld");
	
	Node* shortNode = list::from_string("oWor");
	EXPECT_EQ(list::compare(list::find_list(longNode, shortNode), list::from_string("oWorld")), 0);

	shortNode = list::from_string("rld");
	EXPECT_EQ(list::compare(list::find_list(longNode, shortNode), list::from_string("rld")), 0);
	EXPECT_NE(list::compare(list::find_list(longNode, shortNode), list::from_string("World")), 0);

	shortNode = list::from_string("z");
	EXPECT_EQ(list::find_list(longNode, shortNode), nullptr);

}



/*

TEST(ListTests, ReplaceMe) {
    EXPECT_TRUE(false);
}




// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, ReplaceMe) {
    EXPECT_TRUE(false);
}*/
