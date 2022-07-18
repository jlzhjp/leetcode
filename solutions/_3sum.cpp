#include "pch.h"

namespace _3Sum {
using namespace std;

class Solution {
#define IS(i) (static_cast<size_t>(i))
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    if (nums.front() > 0 || nums.back() < 0) {
      return {};
    }

    if (nums.front() == 0 && nums.back() == 0) {
      return { {0, 0, 0} };
    }

    vector<vector<int>> results;

    int i = 0;
    while (i < nums.size() - 2) {
      int j = i + 1;
      int k = nums.size() - 1;

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum < 0) {
          do ++j; while (j < k && nums[j] == nums[IS(j) - 1]);
        } else if (sum > 0) {
          do --k; while (j < k && nums[k] == nums[IS(k) + 1]);
        } else {
          results.push_back({ nums[i], nums[j], nums[k] });
          do ++j; while (j < k && nums[j] == nums[IS(j) - 1]);
          do --k; while (j < k && nums[k] == nums[IS(k) + 1]);
        }
      }

      do ++i; while (nums[i] == nums[IS(i) - 1] && i < nums.size() - 2);
    }

    return results;
  }

#undef IS
};
}
