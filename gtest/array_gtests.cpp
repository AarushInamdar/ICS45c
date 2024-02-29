#include <gtest/gtest.h>
#include <string>
#include "array.hpp"
#include "alloc.hpp"
using namespace std;




TEST(ArrayTests, Length) {
    Array<int> arr{3};
    EXPECT_EQ(arr.length(), 3);

    Array<string> arr2{10};
    EXPECT_EQ(arr2.length(), 10);
	
	Array<double> arr3{};
    EXPECT_EQ(arr3.length(), 0);

}

TEST(ArrayTests, Subscript) {
    Array<int> arr{10};
    arr[0] = 3;
    arr[3] = 5;
    EXPECT_EQ(arr[0], 3);
    EXPECT_EQ(arr[3], 5);

	Array<string> stringArr{4};
	stringArr[0] = "Aarush"; 
	stringArr[2] = "MyName";
	EXPECT_EQ(stringArr[0], "Aarush");
    EXPECT_EQ(stringArr[2], "MyName");

}

TEST(ArrayTests, Print) {
    stringstream out;

    Array<int> arr{3};
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    out << arr;

    EXPECT_EQ(out.str(), "       0       1       2");
}

TEST(ArrayTests, Read) {
    stringstream in{"1 2 3 4"};

    Array<int> arr{3};
    in >> arr;

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(ArrayTests, OutOfBounds) {
     Array<int> arr{10};
     EXPECT_ANY_THROW(arr[11]);
 }

TEST(ArrayTests, CopyConstructor) {
     Array<int> arr{10};
	 
	 auto fn = [](int x) -> int {return x+1;};
	 arr.fill_with_fn(fn);

     Array<int> arr2{arr};
     EXPECT_EQ(arr2.length(), 10);
     EXPECT_EQ(arr2[0], 1);
     EXPECT_EQ(arr2[9], 10);

     Array<string> empty;
     Array<string> arr3{empty};
     EXPECT_EQ(arr3.length(), 0);
 }

 TEST(ArrayTests, MoveConstructor) {
     AllocationTracker tracker;

	 auto fn = [](int x) -> int {return x+1;};
     Array<int> arr{10};
     arr.fill_with_fn(fn);

     std::size_t allocs_before_move = tracker.get_num_allocations();
     Array arr2{std::move(arr)};
     std::size_t allocs_after_move = tracker.get_num_allocations();

     EXPECT_EQ(allocs_before_move, allocs_after_move);

     EXPECT_EQ(arr2.length(), 10);
     EXPECT_EQ(arr2[0], 1);
     EXPECT_EQ(arr2[9], 10);

     Array<string> empty;
     Array arr3{std::move(empty)};
     EXPECT_EQ(arr3.length(), 0);
 }

 TEST(ArrayTests, Swap) {
     AllocationTracker tracker;

	 auto fn = [](int x) -> int {return x+1;};

	 Array<int> arr{12};
     arr.fill_with_fn(fn);
     Array<int> arr2{2};
     arr2.fill_with_fn(fn);

     std::size_t allocs_before_swap = tracker.get_num_allocations();
     swap(arr, arr2);
     std::size_t allocs_after_swap = tracker.get_num_allocations();

     EXPECT_EQ(allocs_before_swap, allocs_after_swap);

     EXPECT_EQ(arr2.length(), 12);
     EXPECT_EQ(arr2[0], 1);
}

TEST(ArrayTests, CopyAssignment) {
     
	 auto fn = [](int x) -> int {return x+1;};

	 Array<int> arr{10};
     arr.fill_with_fn(fn);

     Array<int> arr2{2};
     arr2.fill_with_fn(fn);

     arr = arr2;

     EXPECT_EQ(arr.length(), 2);
     EXPECT_EQ(arr[0], 1);
     EXPECT_NE(arr[1], 1);

     EXPECT_EQ(arr2.length(), 2);
     EXPECT_EQ(arr2[0], 1);
     EXPECT_NE(arr2[1], 1);

     arr = arr;

     EXPECT_EQ(arr.length(), 2);
     EXPECT_EQ(arr[0], 1);
     EXPECT_EQ(arr[1], 2);
 }

 TEST(ArrayTests, MoveAssignment) {
     AllocationTracker tracker;

	 auto fn = [](int x) -> int {return x+1;};
     Array<int> arr{10};
     arr.fill_with_fn(fn);

     Array<int> arr2{2};
     arr2.fill_with_fn(fn);

     std::size_t allocs_before_move = tracker.get_num_allocations();
     arr = std::move(arr2);
     std::size_t allocs_after_move = tracker.get_num_allocations();
     EXPECT_EQ(allocs_before_move, allocs_after_move);

     EXPECT_EQ(arr.length(), 2);
     EXPECT_EQ(arr[0], 1);
     EXPECT_EQ(arr[1], 2);


     arr2 = Array<int>{5};
     EXPECT_EQ(arr2.length(), 5);
     arr2 = std::move(arr2);
     arr2 = Array<int>{7};
     EXPECT_EQ(arr2.length(), 7);
 }

