/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.86%)
 * Likes:    26287
 * Dislikes: 846
 * Total Accepted:    5.3M
 * Total Submissions: 11.1M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 * 
 * 
 * 
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * @brief Method 1
 *        TC O(N^2)
 *        SC O(1) 
 * 
 * @param nums 
 * @param numsSize 
 * @param target 
 * @param returnSize 
 * @return int* 
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *)malloc((*returnSize = 2) * sizeof(int));
    int flag = 0;
    for (result[0] = 0; result[0] < numsSize - 1; result[0]++)
    {
        for (result[1] = result[0] + 1; result[1] < numsSize; result[1]++)
        {
            if (nums[result[0]] + nums[result[1]] == target)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    return result;
}
// @lc code=end
