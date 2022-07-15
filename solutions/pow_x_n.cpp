#include "pch.h"

namespace Pow {
using namespace std;
class Solution {
  map<int, double> cache{};

public:
  double myPow(double x, int n) {
    if (x == 1) {
      return 1;
    }

    if (n == 0) {
      return 1;
    }

    if (n == 1) {
      return x;
    }

    if (n == -1) {
      return 1. / x;
    }

    auto iter = cache.find(n);
    if (iter != cache.end()) {
      return iter->second;
    }

    double result = 0;
    double p = myPow(x, n / 2);
    if (n % 2 == 0) {
      result = p * p;
    } else {
      if (n < 0) {
        result = p * p / x;
      } else {
        result = p * p * x;
      }
    }

    cache.insert({ n, result });

    return result;
  }
};

TEST(Pow, Example1) {
  Solution s;
  double val = s.myPow(2., 10);
  ASSERT_DOUBLE_EQ(val, 1024.);
}

TEST(Pow, Example2) {
  Solution s;
  double val = s.myPow(2.1, 3);
  ASSERT_DOUBLE_EQ(val, 9.261);
}

TEST(Pow, Example3) {
  Solution s;
  double val = s.myPow(2., -2);
  ASSERT_DOUBLE_EQ(val, 0.25);
}

TEST(Pow, Lowest) {
  Solution s;
  double val = s.myPow(2., -2147483648);
  ASSERT_DOUBLE_EQ(val, 0);
}

TEST(Pow, OddNegativeComponent) {
  Solution s;
  double val = s.myPow(2, -3);
  ASSERT_DOUBLE_EQ(val, 0.125);
}
}
