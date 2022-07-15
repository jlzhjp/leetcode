#include "pch.h"

using namespace std;

namespace MaxAreaOfIsland {
class Solution {
private:
  int calculate_area(vector<vector<int>> &grid, size_t i, size_t j) {
#define ISLAND(integer) (integer & 1U)
#define VISITED(integer) (integer & (1U << 7))

    int area = 0;

    if (VISITED(grid[i][j])) {
      return 0;
    }

    grid[i][j] |= (1U << 7);

    if (ISLAND(grid[i][j])) {
      area += 1;
      if (i > 0 && ISLAND(grid[i - 1][j])) {
        area += calculate_area(grid, i - 1, j);
      }
      if (j > 0 && ISLAND(grid[i][j - 1])) {
        area += calculate_area(grid, i, j - 1);
      }
      if (i < grid.size() - 1 && ISLAND(grid[i + 1][j])) {
        area += calculate_area(grid, i + 1, j);
      }
      if (j < grid[i].size() - 1 && ISLAND(grid[i][j + 1])) {
        area += calculate_area(grid, i, j + 1);
      }
    }

    return area;

#undef ISLAND
#undef VISITED
  }

public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int max = 0;
    for (size_t i = 0; i != grid.size(); ++i) {
      for (size_t j = 0; j != grid[i].size(); ++j) {
        int area = calculate_area(grid, i, j);
        if (area > max) {
          max = area;
        }
      }
    }
    return max;
  }
};

TEST(MaxAreaOfIsland, Example) {
  vector<vector<int>> grid = {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}
  };

  Solution s;
  ASSERT_EQ(s.maxAreaOfIsland(grid), 6);
}

TEST(MaxAreaOfIsland, x2) {
  vector<vector<int>> grid = {
    {0, 1},
    {1, 0}
  };

  Solution s;
  ASSERT_EQ(s.maxAreaOfIsland(grid), 1);
}
}