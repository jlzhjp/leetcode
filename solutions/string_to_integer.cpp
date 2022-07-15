#include "pch.h"

// Implement the myAtoi(string s) function,
// which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
// 
// The algorithm for myAtoi(string s) is as follows:
// 
// Read in and ignore any leading whitespace.

// Check if the next character (if not already at the end of the string) is '-' or '+'.
// Read this character in if it is either.
// This determines if the final result is negative or positive respectively.

// Assume the result is positive if neither is present.
// Read in next the characters until the next non-digit character or the end of the input is reached.
// The rest of the string is ignored.

// Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32).
// If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).

// If the integer is out of the 32-bit signed integer range [-231, 231 - 1],
// then clamp the integer so that it remains in the range. Specifically,
// integers less than -231 should be clamped to -231,
// and integers greater than 231 - 1 should be clamped to 231 - 1.

// Return the integer as the final result.

// Note:
// 
// Only the space character ' ' is considered a whitespace character.
// Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

using namespace std;

int myAtoi(string s) {
#define C2I(ch) (ch - '0')

  using iterator = string::iterator;

  int sign = 1;
  constexpr int upper_bound = numeric_limits<int>::max();
  constexpr int lower_bound = numeric_limits<int>::lowest();

  iterator iter = s.begin();
  while (*iter == ' ') {
    ++iter;
  }

  if (*iter == '-') {
    sign = -1;
    ++iter;
  } else if (*iter == '+') {
    sign = 1;
    ++iter;
  }

  int result = 0;

  if (iter < s.end() && *iter >= '0' && *iter <= '9') {
    result = C2I(*iter) * sign;
    ++iter;
  }

  while (iter < s.end() && *iter >= '0' && *iter <= '9') {
    if (sign > 0 && result > (upper_bound - C2I(*iter)) / 10) {
      return upper_bound;
    } else if (sign < 0 && result < (lower_bound + C2I(*iter)) / 10) {
      return lower_bound;
    }

    result *= 10;
    result += C2I(*iter) * sign;
    ++iter;
  }

  return result;

#undef C2I
}

TEST(StringToInteger, Foo) {
  ASSERT_EQ(myAtoi("42"), 42);
}

TEST(StringToInteger, Neagtive) {
  ASSERT_EQ(myAtoi("-42"), -42);
}

TEST(StringToInteger, WithTrailingWords) {
  ASSERT_EQ(myAtoi("4193 with words"), 4193);
}

TEST(StringToInteger, WithStartingWords) {
  ASSERT_EQ(myAtoi("words with 4193 "), 0);
}

TEST(StringToInteger, Overflow) {
  ASSERT_EQ(myAtoi("91283472332"), numeric_limits<int>::max());
}

TEST(StringToInteger, Underflow) {
  ASSERT_EQ(myAtoi("-91283472332"), numeric_limits<int>::lowest());
}
TEST(StringToInteger, _2147483648) {
  ASSERT_EQ(myAtoi("2147483648"), numeric_limits<int>::max());
}
