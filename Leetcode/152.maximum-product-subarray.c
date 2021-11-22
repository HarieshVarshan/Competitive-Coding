/*
 * @lc app=leetcode id=152 lang=c
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (33.68%)
 * Likes:    8916
 * Dislikes: 279
 * Total Accepted:    587.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find a contiguous non-empty subarray within the
 * array that has the largest product, and return the product.
 * 
 * It is guaranteed that the answer will fit in a 32-bit integer.
 * 
 * A subarray is a contiguous subsequence of the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * 
 */

// @lc code=start


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int maxProduct(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int minSub = nums[0], maxSub = nums[0];
    int maxProductSub = nums[0];

    for (int it = 1; it < numsSize; it++)
    {
        /**
         * element is negative so we swap max and min
         * because when multiplying negative with a negative, 
         * number becomes positive so minimum negative number will become the maximum number
         */
        if (nums[it] < 0)
            swap(&minSub, &maxSub);

        // update all the sub values
        maxSub = max(maxSub * nums[it], nums[it]);
        minSub = min(minSub * nums[it], nums[it]);
        // choose max product to be the max between the maxProduct till now and maxSub
        maxProductSub = max(maxProductSub, maxSub);
    }
    return maxProductSub;
}
// @lc code=end

