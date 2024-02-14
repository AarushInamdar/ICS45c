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
    
	ASSERT_EQ(foo_list->next, nullptr);


	Node* const emptyStringHead = list::from_string("");
	Node* eString = emptyStringHead;

	EXPECT_EQ(eString, nullptr);
	
	
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
    
	Node* hello = list::from_string("hello");
	Node* hella = list::from_string("hella");
	Node* hellb = list::from_string("hellb");
	Node* helld = list::from_string("helld");


	EXPECT_EQ(list::compare(hello, hello), 0);

	EXPECT_EQ(list::compare(hella, hellb), -1);

	EXPECT_EQ(list::compare(helld, hellb), 1);


	list::free(hello);
	list::free(hella);
	list::free(hellb);
	list::free(helld);
}

TEST(ListTests, CompareN) {
    
	Node* hello = list::from_string("hello");
	Node* hella = list::from_string("hella");
	Node* hellb = list::from_string("hellb");
	Node* helld = list::from_string("helld");
	Node* heatd = list::from_string("heatd");
	Node* heftd = list::from_string("heftd");


	EXPECT_EQ(list::compare(hello, hello, 5), 0);

	
	EXPECT_EQ(list::compare(hella, hellb, 5), -1);
	//list::print(std::cout, hellb);
	
	EXPECT_EQ(list::compare(helld, hellb, 5), 1);
	//list::print(std::cout, hellb);
	
	EXPECT_EQ(list::compare(hella, hellb, 3), 0);
	//list::print(std::cout, hellb);

	EXPECT_EQ(list::compare(heatd, heftd, 3), -1);

	list::free(hello);
	list::free(hella);
	list::free(hellb);
	list::free(helld);
	list::free(heatd);
	list::free(heftd);
}


TEST(ListTests, Copy) {
    Node* const head = list::from_string("foo");
	Node* myNode = list::copy(head);
	
		
	EXPECT_EQ(list::compare(head, myNode), 0);


	
	Node* const extreme  = list::from_string("");
	Node* myExtreme = list::copy(extreme);
	EXPECT_EQ(list::compare(extreme, myExtreme), 0);

	list::free(head);
	list::free(myNode);
	list::free(extreme);
	list::free(myExtreme);

}


TEST(ListTests, Last) {
    Node* hw = list::from_string("helloworld");
	Node* lastd = list::from_string("d");

	EXPECT_EQ(list::compare(last(hw), lastd),0);
	std::cout << "Function Last: " << std::endl;
	
	list::print(std::cout, last(hw));



	Node* nothing = list::from_string("a");
	EXPECT_EQ(list::compare(last(nothing), nothing), 0);


	Node* hwZ = list::from_string("helloworldZ");
	Node* lastZd = list::from_string("Zd");
	EXPECT_NE(list::compare(last(hwZ), lastZd),0);

	list::free(hw);
	list::free(hwZ);
	list::free(nothing);
	list::free(lastd);
	list::free(lastZd);

}


TEST(ListTests, Append) {
    
Node* hello = list::from_string("hello");
Node* world = list::from_string("world");

	Node* hwa = list::append(hello, world);
	Node* hw = list::from_string("helloworld");
	std::cout << "Hwa: " << std::endl;
	list::print(std::cout, hwa);
	std::cout << "Hw: helloworld" << std::endl;


	EXPECT_EQ(list::compare(hwa, hw), 0);

	Node* hi = list::from_string("hi");
	
	Node* hwb = list::append(hi, world);
	

	EXPECT_NE(list::compare(hwb, hwa), 0);


	list::free(hw);
	list::free(hwa);
	list::free(hwb);
	list::free(hello);
	list::free(world);
	list::free(hi);


}





TEST(ListTests, Nth) {
    Node* myNode = list::from_string("HelloWorld");
	
	Node* myP = list::nth(myNode, 3);
	EXPECT_EQ(myP->data, 'l');


	Node* myPa = list::nth(myNode, 6);
	EXPECT_EQ(myPa->data, 'W');


	Node* myPb = list::nth(myNode, 1);
	EXPECT_EQ(myPb->data, 'H');



	list::free(myNode);

}



TEST(ListTests, Index) {
    Node* longNode = list::from_string("HelloWorld");
	Node* shortNode = list::from_string("World");

	EXPECT_EQ(index(longNode, shortNode), 5);

	Node* shortNodeD = list::from_string("d");
	
	EXPECT_EQ(index(longNode, shortNodeD), 9);

	Node* shortNodeEl = list::from_string("el");
	EXPECT_EQ(index(longNode, shortNodeEl), 1);

	list::free(longNode);
	list::free(shortNode);
	list::free(shortNodeD);
	list::free(shortNodeEl);

}


TEST(ListTests, FindChar) {
    Node* longNode = list::from_string("HelloWorld");
	char myChar = 'W';

	Node* findWorld = list::find_char(longNode, myChar);
	Node* world = list::from_string("World");
	EXPECT_EQ(list::compare(findWorld, world), 0);

	

	myChar = 'r';
	Node* findR = list::find_char(longNode, myChar);
	Node* rld = list::from_string("rld");

	EXPECT_EQ(list::compare(findR, rld), 0);
	EXPECT_NE(list::compare(findR, world), 0);

	

	myChar = 'z';
	Node* nothing = list::find_char(longNode, myChar);
	EXPECT_EQ(nothing, nullptr);

	


	list::free(longNode);
	list::free(world);
	list::free(rld);
	list::free(nothing);

}



TEST(ListTests, FindList) {
    Node* longNode = list::from_string("HelloWorld");
	Node* shortNode = list::from_string("ello");

	Node* res = list::find_list(longNode, shortNode);
	Node* check = list::from_string("elloWorld");
	std::cout << "this is supposed to be oWorld: ";
	list::print(std::cout, res);
	std::cout << " " << std::endl;
	EXPECT_EQ(list::compare(res, check), 0);


	Node* shortNodeB = list::from_string("rld");
	Node* res2 = list::find_list(longNode, shortNodeB);
	Node* check2 = list::from_string("World");
	std::cout << "this is supposed to be rld: ";
	list::print(std::cout, res2);
	std::cout << std::endl;

	EXPECT_EQ(list::compare(res2, shortNodeB), 0);
	EXPECT_NE(list::compare(res2, check2), 0);



	Node* shortNodeC = list::from_string("z");
	Node* res3 = list::find_list(longNode, shortNodeC);
	EXPECT_EQ(res3, nullptr);
	
	

	list::free(longNode);
	list::free(shortNode);
	list::free(check);
	list::free(shortNodeB);
	list::free(check2);
	list::free(shortNodeC);



}


TEST(ListTests, Reverse) {
	Node* longNode = list::from_string("HelloWorld");
	Node* reversedTest = list::from_string("dlroWolleH");
	Node* reversal = list::reverse(longNode);

	EXPECT_EQ(list::compare(reversal, reversedTest), 0);


	Node* longNode2 = list::from_string("ZZZZ");
	Node* reversedTest2 = list::from_string("ZZZZ");
	Node* reversal2 = list::reverse(longNode2);

	EXPECT_EQ(list::compare(reversal2, reversedTest2), 0);

	
	Node* longNode3 = list::from_string("");
	Node* reversedTest3= list::from_string("");
	Node* reversal3 = list::reverse(longNode);
	EXPECT_EQ(list::compare(reversal3, reversedTest), 0);


	list::free(longNode);
	list::free(reversedTest);
	list::free(reversal);
	list::free(longNode2);
	list::free(reversedTest2);
	list::free(reversal2);
	list::free(longNode3);
	list::free(reversedTest3);
	list::free(reversal3);

}


/*

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, ReplaceMe) {
    EXPECT_TRUE(false);
}*/
