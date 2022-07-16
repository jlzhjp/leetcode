#include "pch.h"

namespace CombinationSum {

using namespace std;

class Solution {
  vector<vector<int>> results{};

private:
  void combination_sum(vector<int> &candidates,
    int target,
    vector<int> &prev) {

    if (target == 0) {
      results.push_back(prev);
      return;
    }

    if (target < 0) {
      return;
    }

    for (int num : candidates) {
      if (prev.empty() || num >= prev.back()) {
        prev.push_back(num);
        combination_sum(candidates, target - num, prev);
        prev.pop_back();
      }
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> prev;
    combination_sum(candidates, target, prev);
    return results;
  }
};

TEST(CombinationSum, Example1) {
  Solution s;
  vector<int> nums{ 2, 3, 6, 7 };
  vector<vector<int>> results = s.combinationSum(nums, 7);
  vector<vector<int>> expected{ {2, 2, 3}, { 7 } };

  ASSERT_EQ(results, expected);
}

}
