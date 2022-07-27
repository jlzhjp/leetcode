#include "pch.h"

namespace InorderTranversal {
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
  void _inorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    _inorderTraversal(root->left);

    result.push_back(root->val);

    _inorderTraversal(root->right);
  }

public:
  vector<int> inorderTraversal(TreeNode *root) {
    _inorderTraversal(root);
    return result;
  }
};

TEST(InorderTraversal, Example1) {
  TreeNode n2(3);
  TreeNode n1(2, &n2, nullptr);
  TreeNode root(1, nullptr, &n1);

  Solution s;

  vector<int> actual = s.inorderTraversal(&root);
  vector<int> expected{ 1, 3, 2 };

  ASSERT_EQ(actual, expected);
}

}