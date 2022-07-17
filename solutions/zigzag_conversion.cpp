#include "pch.h"

namespace ZigzagConversion {
using namespace std;

string convert(string s, int numRows) {
  if (numRows == 1) {
    return s;
  }

  int span = (numRows - 1) * 2;
  size_t row = numRows;
  size_t row_len = (s.size() + row) / (row - 1);

  vector<string> results(numRows);
  for (int i = 0; i != numRows; ++i) {
    results.reserve(row_len);
  }

  for (size_t i = 0; i < s.size(); i += span) {
    results[0].push_back(s[i]);
    for (size_t j = 0; j != row - 2; ++j) {
      size_t pos1 = i + j + 1;
      if (pos1 < s.size()) {
        results[j + 1].push_back(s[pos1]);
      }

      size_t pos2 = i + span - j - 1;
      if (pos2 < s.size()) {
        results[j + 1].push_back(s[pos2]);
      }
    }

    if (i + row - 1 < s.size()) {
      results[row - 1].push_back(s[i + row - 1]);
    }
  }

  s.clear();
  for (auto &str : results) {
    s.append(str);
  }

  return s;
}

TEST(ZigzagConversion, _1Row) {
  string input = "PAYPALISHIRING";
  string expected = "PAYPALISHIRING";
  string actual = convert(input, 1);
  ASSERT_EQ(actual, expected);
}

TEST(ZigzagConversion, _2Row) {
  string input = "PAYP";
  string expected = "PYAP";
  string actual = convert(input, 2);
  ASSERT_EQ(actual, expected);
}

TEST(ZigzagConversion, _3Row) {
  string input = "PAYPALISHIRING";
  string expected = "PAHNAPLSIIGYIR";
  string actual = convert(input, 3);
  ASSERT_EQ(actual, expected);
}

TEST(ZigzagConversion, _4Row) {
  string input = "PAYPALISHIRING";
  string expected = "PINALSIGYAHRPI";
  string actual = convert(input, 4);
  ASSERT_EQ(actual, expected);
}

}
