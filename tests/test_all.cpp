#include <gtest/gtest.h>

#include "function.cpp"
TEST (Function, Normal) {
  EXPECT_EQ(8, function(2,2));
  EXPECT_EQ(4, function(2,1));
}
TEST (Function, SecondTest) {
  EXPECT_EQ(6, function(1,2));
  EXPECT_EQ(3, function(1,1));
}
