#include "pch.h"

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

namespace RotateImage {

using namespace std;

void rotate(vector<vector<int>> &matrix) {
  size_t n = matrix.size();
  for (size_t i = 0; i != n; ++i) {
    for (size_t j = i + 1; j != n; ++j) {
      std::swap(matrix[i][j], matrix[j][i]);
    }

    vector<int>::iterator p = matrix[i].begin(), q = --matrix[i].end();

    while (p < q) {
      std::swap(*p, *q);
      ++p;
      --q;
    }
  }
}

TEST(RotateImage, x3) {
  vector<vector<int>> matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  vector<vector<int>> expected = {
    {7, 4, 1},
    {8, 5, 2},
    {9, 6, 3}
  };

  rotate(matrix);
  ASSERT_EQ(matrix, expected);
}

TEST(RotateImage, x4) {
  vector<vector<int>> matrix = {
    {5, 1, 9, 11},
    {2, 4, 8, 10},
    {13, 3, 6, 7},
    {15, 14, 12, 16}
  };
  vector<vector<int>> expected = {
    {15, 13, 2, 5},
    {14, 3, 4, 1},
    {12, 6, 8, 9},
    {16, 7, 10, 11}
  };

  rotate(matrix);
  ASSERT_EQ(matrix, expected);
}

}

