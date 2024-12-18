/*
Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums.
If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

Constraints:
1 <= nums.length <= 10^4
-10^4 < nums[i], target < 10^4
All the integers in nums are unique.
nums is sorted in ascending order.
 */

/*
Note: Always check the middle.
The end condition is when no more branches can be found.
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0, end = nums.size() - 1, middle;

        while (true) {
            middle = (first + end) / 2;
            /* No more branches when middle is equal the first or the end */
            if ((first == middle) || (end == middle)) {
                if (target == nums[first])
                    return first;
                else if (target == nums[end])
                    return end;
                else
                    return -1;
            }
            /* if found */
            else if (target == nums[middle]) {
                return middle;
            }
            /* If there are more branches */
            else {
                if (nums[middle] >= target) {
                    end = middle;
                } else {
                    first = middle;
                }
            }
        }
    }
};