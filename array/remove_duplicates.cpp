#include "pch.h"

using namespace std;

// Given an integer array nums sorted in non-decreasing order,
// remove the duplicates in-place such that each unique element appears only once.
// The relative order of the elements should be kept the same.
//
// Since it is impossible to change the length of the array in some languages,
// you must instead have the result be placed in the first part of the array nums.
// More formally, if there are k elements after removing the duplicates,
// then the first k elements of nums should hold the final result.
// It does not matter what you leave beyond the first k elements.
//
// Return k after placing the final result in the first k slots of nums.
//
// Do not allocate extra space for another array.
// You must do this by modifying the input array in-place with O(1) extra memory.

int removeDuplicates(vector<int> &nums) {
  using iterator = vector<int>::iterator;

  iterator i1 = nums.begin();
  iterator i2 = nums.begin();

  int k = 1;

  while (i2 != nums.end()) {
    if (*i2 == *i1) {
      ++i2;
    } else {
      *++i1 = *i2;
      ++k;
    }
  }

  nums.resize(k);

  return k;
}

TEST(RemoveDuplicates, Example1) {
  vector<int> nums = {1, 1, 2};
  vector<int> expectedNums = {1, 2};

  int k = removeDuplicates(nums);

  ASSERT_EQ(k, expectedNums.size());
  ASSERT_EQ(nums, expectedNums);
}

TEST(RemoveDuplicates, Example2) {
  vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
  vector<int> expectedNums = { 0, 1, 2, 3, 4 };

  int k = removeDuplicates(nums);
  ASSERT_EQ(k, expectedNums.size());
  ASSERT_EQ(nums, expectedNums);
}
