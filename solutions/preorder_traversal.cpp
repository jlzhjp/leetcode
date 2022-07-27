#include "pch.h"

namespace PreorderTraversal {
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  vector<int> result;
  void _preorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    result.push_back(root->val);

    _preorderTraversal(root->left);
    _preorderTraversal(root->right);
  }

public:
  vector<int> preorderTraversal(TreeNode *root) {
    _preorderTraversal(root);
    return result;
  }
};

TEST(PreorderTraversal, Example1) {
  Solution s;
  TreeNode n2(3);
  TreeNode n1(2, &n2, nullptr);
  TreeNode root(1, nullptr, &n1);

  vector<int> actual = s.preorderTraversal(&root);
  vector<int> expected{ 1, 2 ,3 };

  ASSERT_EQ(expected, actual);
}

}
