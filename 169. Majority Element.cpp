/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

Follow-up: Could you solve the problem in linear time and in O(1) space?

https://leetcode.com/problems/majority-element/description/
*/

#include <unordered_map>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> hashMap;
        int majority = nums.size() / 2;

        //Use hash map to count the appear times of each number
        for (int i : nums) {
            hashMap[i]++;
            if (hashMap[i] > majority)
                return i;
        }
        return 0;
    }
};
