#
# @lc app=leetcode id=2032 lang=python3
#
# [2032] Two Out of Three
#
# https://leetcode.com/problems/two-out-of-three/description/
#
# algorithms
# Easy (71.81%)
# Likes:    152
# Dislikes: 20
# Total Accepted:    16K
# Total Submissions: 22.3K
# Testcase Example:  '[1,1,3,2]\n[2,3]\n[3]'
#
# Given three integer arrays nums1, nums2, and nums3, return a distinct array
# containing all the values that are present in at least two out of the three
# arrays. You may return the values in any order.
#
# Example 1:
#
#
# Input: nums1 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
# Output: [3,2]
# Explanation: The values that are present in at least two arrays are:
# - 3, in all three arrays.
# - 2, in nums1 and nums2.
#
#
# Example 2:
#
#
# Input: nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
# Output: [2,3,1]
# Explanation: The values that are present in at least two arrays are:
# - 2, in nums2 and nums3.
# - 3, in nums1 and nums2.
# - 1, in nums1 and nums3.
#
#
# Example 3:
#
#
# Input: nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
# Output: []
# Explanation: No value is present in at least two arrays.
#
#
#
# Constraints:
#
#
# 1 <= nums1.length, nums2.length, nums3.length <= 100
# 1 <= nums1[i], nums2[j], nums3[k] <= 100
#
#
#

# @lc code=start
class Solution:
    # Method 1 - Using Dictionary
    def twoOutOfThree_m1(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        # To remove duplicates list is converted to set
        nums1 = list(set(nums1))
        nums2 = list(set(nums2))
        nums3 = list(set(nums3))

        hashmap = {}  # empty dictionary is created

        for item in nums1:
            if(item in hashmap):
                # if item already present, increment its value
                hashmap[item] += 1
            else:
                hashmap[item] = 1  # if item not present create entry item : 1

        for item in nums2:
            if(item in hashmap):
                hashmap[item] += 1
            else:
                hashmap[item] = 1

        for item in nums3:
            if(item in hashmap):
                hashmap[item] += 1
            else:
                hashmap[item] = 1

        res = []
        for key in hashmap:
            if(hashmap[key] == 2 or hashmap[key] == 3):
                res.append(key)

        return res

    # Method 2 - Using Set Operations
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        # (num1 intersection nums2) union (nums2 intersection nums3) union (nums1 intersection nums3)
        return set(nums1) & set(nums2) | set(nums2) & set(nums3) | set(nums1) & set(nums3)
# @lc code=end
