#include "pch.h"

// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order, and each of their nodes
// contains a single digit. Add the two numbers and return the sum as a linked
// list.

// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading
// zeros.

// Definition for singly-linked list.

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode head;
    ListNode *cur = &head;

    int plus1 = 0;

    for (ListNode *n1 = l1, *n2 = l2;; n1 = n1->next, n2 = n2->next) {

      int bit = n1->val + n2->val + plus1;

      if (bit >= 10) {
        cur->next = new ListNode(bit - 10);
        plus1 = 1;
      } else {
        cur->next = new ListNode(10);
        plus1 = 0; 
      }
      cur = cur->next;
    }
  }
};
