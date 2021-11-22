/*
 * @lc app=leetcode id=338 lang=c
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Easy (72.00%)
 * Likes:    5124
 * Dislikes: 251
 * Total Accepted:    439.3K
 * Total Submissions: 610K
 * Testcase Example:  '2'
 *
 * Given an integer n, return an array ans of length n + 1 such that for each i
 * (0 <= i <= n), ans[i] is the number of 1's in the binary representation of
 * i.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2
 * Output: [0,1,1]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 5
 * Output: [0,1,1,2,1,2]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 10^5
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with a runtime of O(n log n). Can
 * you do it in linear time O(n) and possibly in a single pass?
 * Can you do it without using any built-in function (i.e., like
 * __builtin_popcount in C++)?
 * 
 * 
 */

// @lc code=start

int countOnes(int num)
{
    int count = 0;
    while (num)
    {
        if (num & 1 == 1)
            count += 1;
        num = (num >> 1);
    }
    return count;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * @brief Method 1
 *        TC O(N*logN)
 *        SC O(1)
 * 
 * @param n 
 * @param returnSize 
 * @return int* 
 */
int *countBits_m1(int n, int *returnSize)
{
    *returnSize = n + 1;
    int *result = (int *)malloc((n + 1) * sizeof(int));
    result[0] = 0; /* for n = 0 */
    if (n == 0)
        return result;
    for (int i = 1; i <= n; i++)
        result[i] = countOnes(i);
    return result;
}

/**
 * @brief Method 2
 *        TC O(N)
 *        SC O(1)
 * 
 * @param n 
 * @param returnSize 
 * @return int* 
 */
int *countBits(int n, int *returnSize)
{
    *returnSize = n + 1;
    int *result = (int *)malloc((n + 1) * sizeof(int));
    result[0] = 0; /* For n = 0 */
    if (n == 0)
        return result;
    for (int i = 1; i <= n; i++)
    {
        if(i%2 == 0)
            result[i] = result[i/2];
        else
            result[i] = result[i-1]+1;
    }
    return result;
}
// @lc code=end
