#include "pch.h"

namespace PostorderTraversal {
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
  void _postorderTraversal(TreeNode *root, vector<int> &result) {
    if (root == nullptr) {
      return;
    }

    _postorderTraversal(root->left, result);
    _postorderTraversal(root->right, result);
    result.push_back(root->val);
  }
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    _postorderTraversal(root, result);
    return result;
  }
};

TEST(PostorderTraversal, Example1) {
  Solution s;
  TreeNode n2(3);
  TreeNode n1(2, &n2, nullptr);
  TreeNode root(1, nullptr, &n1);

  vector<int> actual = s.postorderTraversal(&root);
  vector<int> expected{ 3, 2 ,1 };

  ASSERT_EQ(expected, actual);
}

}