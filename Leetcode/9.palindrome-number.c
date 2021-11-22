/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (51.67%)
 * Likes:    4427
 * Dislikes: 1920
 * Total Accepted:    1.6M
 * Total Submissions: 3.1M
 * Testcase Example:  '121'
 *
 * Given an integer x, return true if x is palindrome integer.
 * 
 * An integer is a palindrome when it reads the same backward as forward. For
 * example, 121 is palindrome while 123 is not.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: x = 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: x = -101
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= x <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without converting the integer to a string?
 */

// @lc code=start
/**
 * @brief TC O(logN)
 *        SC O(1)
 * 
 * @param x 
 * @return true 
 * @return false 
 */
bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int rev = 0;
    while (x > rev)
    {
        rev = (rev * 10) + (x % 10);
        x /= 10;
    }
    /* x == rev/10 is for odd digit numbers, rev/10 is to get rid of the middle digit */
    return x == rev || x == rev / 10;
}

/**
 * @brief Normal Approach but fails for very large numbers
 * 
 * @param x 
 * @return true 
 * @return false 
 */
bool isPalindrome_m1(int x)
{
    if (x < 0)
        return false;
    int temp = x;
    int rev = 0;
    while (x)
    {
        if ((rev * 10) > 2147483647)
            return false;
        rev = (rev * 10) + (x % 10);
        x /= 10;
    }
    return temp == rev;
}
// @lc code=end
