/* LeetCode 55. Jump Game
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * Example 2:
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 *              jump length is 0, which makes it impossible to reach the last index.
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int p = 0, len = nums.size(), increment = 0, index = 0;
        while (p < len - 1) {
            if (p + nums[p] >= len - 1) return true;
            if (nums[p] == 0) return false;
            int i = p + 1;
            increment = 0; index = 0;
            while (i <= p + nums[p] && i < len) {
                if (nums[i] + i >= increment + index) {
                    increment = nums[i];
                    index = i;
                }
                i++;
            }
            p = index;
        }
        return true;
    }
};
