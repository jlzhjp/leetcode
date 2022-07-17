#include "pch.h"

namespace RemoveElement {
using namespace std;
// Given an integer array nums and an integer val,
// remove all occurrences of val in nums in-place.
// The relative order of the elements may be changed.
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


int removeElement(vector<int> &nums, int val) {
  using iterator = vector<int>::iterator;
  iterator i = nums.begin();
  iterator rear = nums.end();
  int k = static_cast<int>(nums.size());

  while (i != rear) {
    if (*i == val) {
      --rear;
      *i = *rear;
      --k;
    } else {
      ++i;
    }
  }

  nums.resize(k);

  return k;
}

struct TestParam {
  vector<int> input;
  int val;
  vector<int> expected;
};

class Test : public testing::TestWithParam<TestParam> { };

TEST_P(Test , Foo) {
  vector<int> nums = GetParam().input;
  int val = GetParam().val;
  vector<int> expectedNums = GetParam().expected;

  int k = removeElement(nums, val);

  ASSERT_EQ(expectedNums.size(), k);

  sort(expectedNums.begin(), expectedNums.end());
  sort(nums.begin(), nums.end());

  ASSERT_EQ(nums, expectedNums);
}

auto CreateParam(vector<int> input, int val, vector<int> expected) {
  return TestParam{ input, val, expected };
}

INSTANTIATE_TEST_CASE_P(RemoveElement, Test, testing::Values(
  CreateParam({ 3, 2, 2, 3 }, 3, { 2, 2 }),
  CreateParam({ 0, 1, 2, 2, 3, 0, 4, 2 }, 2, { 0, 1, 4, 0, 3 }),
  CreateParam({ 4, 5 }, 5, { 4 }),
  CreateParam({ 2 }, 3, { 2 })));
}
