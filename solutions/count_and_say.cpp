#include "pch.h"

namespace CountAndSay {
using namespace std;
class Solution {
public:
  string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }

    string s = countAndSay(n - 1);
    string result;
    char current_digit = s.front();
    int current_count = 1;
    
    for (string::iterator iter = ++s.begin();; ++iter) {
      if (iter == s.end()) {
        result.push_back(current_count + '0');
        result.push_back(current_digit);
        break;
      } else if (*iter == current_digit) {
        ++current_count;
      } else {
        result.push_back(current_count + '0');
        result.push_back(current_digit);
        current_digit = *iter;
        current_count = 1;
      }
    }

    return result;
  }
};

TEST(CountAndSay, Example1) {
  Solution s;
  ASSERT_EQ(s.countAndSay(1), "1");
}

TEST(CountAndSay, Example2) {
  Solution s;
  string result = s.countAndSay(4);
  ASSERT_EQ(result, "1211");
}

}