#include <gtest/gtest.h>

#include <iostream>

using namespace std;

#include "convert_knots.hpp"

namespace {


//Given Test
TEST(ConvertKnots, Two) {
	EXPECT_NEAR(0.0383593, knots_to_miles_per_minute(2), 0.01);
}

//Test 2
TEST(ConvertKnots, Two) {
	EXPECT_NEAR(19.17966666, knot_to_miles_per_minute(2), 0.01);
}

//Test 3
TEST(ConvertKnots, Three) {
    EXPECT_NEAR(0.057539, knots_to_miles_per_minute(3), 0.01);
}
}
