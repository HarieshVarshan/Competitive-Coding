/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (37.20%)
 * Likes:    7605
 * Dislikes: 382
 * Total Accepted:    1.1M
 * Total Submissions: 3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1], n = 1
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2], n = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * Follow up: Could you do this in one pass?
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

/**
 * @brief TC O(N)
 *        SC O(1)
 * 
 * @param head 
 * @param n 
 * @return struct ListNode* 
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *slow = head, *fast = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    while(!fast) return head->next;
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return head;
}
// @lc code=end
