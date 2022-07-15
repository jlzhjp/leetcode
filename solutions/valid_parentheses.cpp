#include "pch.h"
using namespace std;

namespace ValidParentheses {

class Solution {
private:
  char get_left_pair(char ch) {
    switch (ch) {
      case ')': return '(';
      case ']': return '[';
      case '}': return '{';
    }
    return '\0';
  }
public:
  bool isValid(string s) {
    stack<char> parens{};

    for (char ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        parens.push(ch);
      } else if (parens.empty() || get_left_pair(ch) != parens.top()) {
        return false;
      } else {
        parens.pop();
      }
    }

    if (!parens.empty()) {
      return false;
    }

    return true;
  }
};

TEST(ValidParentheses, Example1) {
  Solution s;
  ASSERT_TRUE(s.isValid("()"));
}

TEST(ValidParentheses, Example2) {
  Solution s;
  ASSERT_TRUE(s.isValid("()[]{}"));
}

TEST(ValidParentheses, Example3) {
  Solution s;
  ASSERT_FALSE(s.isValid("(]"));
}

}
