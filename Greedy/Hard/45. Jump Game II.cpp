/* LeetCode 45. Jump Game II
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 *     Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * Note:
 * 
 * You can assume that you can always reach the last index.
 */
 
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, p = 0, len = nums.size(), increment = 0, index = 0;
        while (p < len - 1) {
            if (p + nums[p] >= len - 1) {
                res++;
                break;
            }
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
            res++;
        }
        return res;
    }
};
