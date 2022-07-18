#include "pch.h"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> map;
  for (int i = 0; i != nums.size(); ++i) {
    auto iter = map.find(nums[i]);
    if (iter != map.end()) {
      return  { iter->second, i };
    } else {
      map.insert({ target - nums[i], i });
    }
  }
  return {};
}

TEST(TwoSum, Example1) {
  vector<int> input{ 2,7,11,15 };
  vector<int> expected{ 0, 1 };
  int target = 9;
  vector<int> actual = twoSum(input, target);

  ASSERT_EQ(expected, actual);
}

TEST(TwoSum, Example2) {
  vector<int> input{ 3, 2, 4 };
  vector<int> expected{ 1, 2 };
  int target = 6;
  vector<int> actual = twoSum(input, target);

  ASSERT_EQ(expected, actual);
}

TEST(TwoSum, Example3) {
  vector<int> input{ 3, 3 };
  vector<int> expected{ 0, 1 };
  int target = 6;
  vector<int> actual = twoSum(input, target);

  ASSERT_EQ(expected, actual);
}
