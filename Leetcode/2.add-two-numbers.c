/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (37.22%)
 * Likes:    14829
 * Dislikes: 3251
 * Total Accepted:    2.3M
 * Total Submissions: 6.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void appendNode(struct ListNode **p, int data)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = data;
    if ((*p) == NULL)
    {
        temp->next = NULL;
        *p = temp;
    }
    else
    {
        struct ListNode *q = *p;
        while (q->next != NULL)
        {
            q = q->next;
        }
        temp->next = NULL;
        q->next = temp;
    }
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int sum = 0;
    struct ListNode *sumLL = NULL;
    while (sum || l1 || l2)
    {
        sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        appendNode(&sumLL, sum % 10);
        sum = sum / 10;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return sumLL;
}
// @lc code=end
