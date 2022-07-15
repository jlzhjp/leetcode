#include "pch.h"

namespace MultiplyStrings {
using namespace std;

class Solution {
#define C2I(ch) (ch - '0')
#define I2C(i) (i + '0')
public:
  string multiply_nx1(const string &num, char factor) {
    string result{};
    int carry = 0;

    for (auto iter = num.rbegin(); iter != num.rend(); ++iter) {
      int val = C2I(*iter) * C2I(factor) + carry;
      carry = val / 10;
      result.push_back(I2C(val % 10));
    }

    if (carry != 0) {
      result.push_back(I2C(carry));
    }

    return string{ result.rbegin(), result.rend() };
  }

  string add(const vector<string> &nums) {
    string result{};

    int carry = 0;
    size_t max_len = max_element(nums.begin(), nums.end(),
      [](const string &s1, const string &s2) { return s1.size() < s2.size(); })
      ->size();

    for (size_t i = 0; i != max_len; ++i) {
      int val = 0;
      for (auto &num : nums) {
          ptrdiff_t index = num.size() - i - 1;
          if (index >= 0) {
            val += C2I(num[index]);
          }
      }
      val += carry;
      carry = val / 10;
      result.push_back(I2C(val % 10));
    }

    if (carry != 0) {
      result.push_back(I2C(carry));
    }

    return string{ result.rbegin(), result.rend() };
  }

public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    vector<string> parts;
    for (int n = 0; n != num2.size(); ++n) {
      string part = multiply_nx1(num1, num2[n]);
      parts.push_back(part + string(num2.size() - n - 1, '0'));
    }

    return add(parts);
  }

#undef C2I
#undef I2C
};

TEST(MultiplyStrings, Nx1) {
  Solution s;
  ASSERT_EQ(s.multiply_nx1("42", '3'), "126");
}

TEST(MultiplyStrings, Add) {
  Solution s;
  ASSERT_EQ(s.add({ "92", "5", "8" }), "105");
}

TEST(MultiplyStrings, Example1) {
  Solution s;
  ASSERT_EQ(s.multiply("2", "3"), "6");
}

TEST(MultiplyStrings, Example2) {
  Solution s;
  ASSERT_EQ(s.multiply("123", "456"), "56088");
}

TEST(MultiplyStrings, Zero) {
  Solution s;
  ASSERT_EQ(s.multiply("9133", "0"), "0");

}
}