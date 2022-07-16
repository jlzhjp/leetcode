#include "pch.h"

// There is an m x n grid with a ball.
// The ball is initially at the position [startRow, startColumn].
// You are allowed to move the ball to one of the four adjacent cells in the grid
// (possibly out of the grid crossing the grid boundary).
// You can apply at most maxMove moves to the ball.
//
// Given the five integers m, n, maxMove, startRow, startColumn,
// return the number of paths to move the ball out of the grid boundary.
// Since the answer can be very large, return it modulo 10^9 + 7.

namespace OutOfBoundaryPaths {

using namespace std;

class Solution {
  map<tuple<int, int, int>, int> cache;
  int mod = 1000000007;

public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    if (startRow == -1 || startColumn == -1 ||
      startRow == m || startColumn == n) {
      return 1;
    }

    if (maxMove == 0) {
      return 0;
    }

    auto iter = cache.find({ startRow, startColumn, maxMove });

    if (iter != cache.end()) {
      return iter->second;
    }

    int result = (
      (findPaths(m, n, maxMove - 1, startRow - 1, startColumn) 
      + findPaths(m, n, maxMove - 1, startRow, startColumn - 1)) % mod
      + (findPaths(m, n, maxMove - 1, startRow + 1, startColumn)
      + findPaths(m, n, maxMove - 1, startRow, startColumn + 1)) % mod
      ) % mod;

    cache.insert({ { startRow, startColumn, maxMove }, result });

    return result;
  }
};

TEST(OutOfBoundaryPaths, Example1) {
  Solution s;
  ASSERT_EQ(s.findPaths(2, 2, 2, 0, 0), 6);
}

TEST(OutOfBoundaryPaths, Example2) {
  Solution s;
  ASSERT_EQ(s.findPaths(1, 3, 3, 0, 1), 12);
}

TEST(OutOfBoundaryPaths, WrongAnswer1) {
  Solution s;
  ASSERT_EQ(s.findPaths(8, 50, 23, 5, 26), 914783380);
}

}
