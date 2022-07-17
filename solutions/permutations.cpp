#include "pch.h"
namespace Permutations {
using namespace std;

class Solution {
  vector<vector<int>> results{};

private:
  void _permute(vector<int> &prev, vector<int> rest) {
    if (rest.empty()) {
      results.push_back(prev);
      return;
    }

    for (int num : rest) {
      prev.push_back(num);
      vector<int> temp{};

      for (int n : rest) {
        if (n != num) {
          temp.push_back(n);
        }
      }
      _permute(prev, move(temp));
      prev.pop_back();
    }
  }
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> prev = {};
    _permute(prev, nums);
    return results;
  }
};

TEST(Permutations, Example1) {
  vector<int> input{ 1, 2, 3 };
  vector<vector<int>> expected{ {1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1} };
  Solution s;

  ASSERT_EQ(s.permute(input), expected);
}

}