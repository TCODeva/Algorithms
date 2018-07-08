/* LeetCode 494. Target Sum
 * You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to target S.
 * 
 * Example 1:
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * Note:
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 */
 
Brute Force using Recursion:

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return helper(nums, S, nums.size()-1);
    }
    
private:
    int helper(vector<int>& nums, int s, int curr) {
        if (curr == 0) {
            int k = 0;
            if (nums[curr] == s) k++;
            if (-nums[curr] == s) k++; 
            return k;
        }
        return helper(nums, s - nums[curr], curr-1) + helper(nums, s + nums[curr], curr-1);
    }
};

Recursion with memorization:

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, INT_MIN));
        return helper(nums, 0, 0, S, dp);
    }
    
private:
    int helper(vector<int>& nums, int s, int curr, int S, vector<vector<int>>& dp) {
        if (curr == nums.size()) {
            if (s == S)
                return 1;
            else
                return 0;
        } else {
            if (dp[curr][s + 1000] != INT_MIN)
                return dp[curr][s + 1000];
            dp[curr][s + 1000] = helper(nums, s - nums[curr], curr+1, S, dp) + helper(nums, s + nums[curr], curr+1, S, dp);
            return dp[curr][s + 1000];
        }
    }
};

