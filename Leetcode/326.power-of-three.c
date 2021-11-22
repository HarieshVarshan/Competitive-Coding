/*
 * @lc app=leetcode id=326 lang=c
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (42.88%)
 * Likes:    546
 * Dislikes: 72
 * Total Accepted:    405.5K
 * Total Submissions: 945.4K
 * Testcase Example:  '27'
 *
 * Given an integer n, return true if it is a power of three. Otherwise, return
 * false.
 * 
 * An integer n is a power of three, if there exists an integer x such that n
 * == 3^x.
 * 
 * 
 * Example 1:
 * Input: n = 27
 * Output: true
 * Example 2:
 * Input: n = 0
 * Output: false
 * Example 3:
 * Input: n = 9
 * Output: true
 * Example 4:
 * Input: n = 45
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= n <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */

// @lc code=start

/**
 * @brief Method 1
 *        TC O(log3N)
 *        SC O(1)
 * 
 * @param n 
 * @return true 
 * @return false 
 */
bool isPowerOfThree_m1(int n)
{
    /* Corner Case - Assumption input is greater than 0*/
    if (n <= 0)
        return 0;

    while (n > 1)
    {
        if (n % 3 != 0)
            return 0;
        n = n / 3;
    }

    return 1;
}

/**
 * @brief Method 2
 *        TC O(1)
 *        SC O(1)
 * 
 * @param n 
 * @return true 
 * @return false 
 */
bool isPowerOfThree(int n)
{
	return n > 0 && 1162261467 % n == 0;
	/* pow(3, floor(log(INT_MAX)/log(3))) = 1162261467  */
}
// @lc code=end

