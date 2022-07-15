#include "pch.h"

// You are given a large integer represented as an integer array digits,
// where each digits[i] is the ith digit of the integer.
// The digits are ordered from most significant to least significant in left-to-right order.
// The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

using namespace std;

vector<int> plusOne(vector<int> &digits) {
  deque<int> result;

  auto r_iter = digits.rbegin();
  *r_iter += 1;

  int carry = 0;

  while (r_iter != digits.rend()) {
    result.push_front((*r_iter + carry) % 10);
    carry = (*r_iter + carry) / 10;
    ++r_iter;
  }

  if (carry != 0) {
    result.push_front(carry);
  }

  return vector<int>{result.begin(), result.end()};
}

TEST(PlusOne, Example1) {
  vector<int> digits{ 1, 2, 3 };
  vector<int> expected{ 1, 2, 4 };
  ASSERT_EQ(plusOne(digits), expected);
}

TEST(PlusOne, Example2) {
  vector<int> digits{ 4, 3, 2, 1 };
  vector<int> expected{ 4, 3, 2, 2 };
  ASSERT_EQ(plusOne(digits), expected);
}

TEST(PlusOne, Example3) {
  vector<int> digits{ 9 };
  vector<int> expected{ 1, 0 };
  ASSERT_EQ(plusOne(digits), expected);
}
