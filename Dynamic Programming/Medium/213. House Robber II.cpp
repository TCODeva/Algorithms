/* LeetCode 213. House Robber II
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Example 1:
 * 
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
 *              because they are adjacent houses.
 * Example 2:
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 */
 
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        return max(helper(nums, 0, nums.size()-2), helper(nums, 1, nums.size()-1));
    }
    
private:
    int helper(vector<int>& nums, int head, int tail) {
        vector<int> dp(tail + 1, 0);
        dp[head] = nums[head]; dp[head+1] = max(nums[head+1], nums[head]);
        for (int i = head + 2; i <= tail; i++) 
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        return dp[tail];
    }
};
