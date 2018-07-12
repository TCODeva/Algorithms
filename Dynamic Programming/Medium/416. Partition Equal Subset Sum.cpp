/* LeetCode 416. Partition Equal Subset Sum
 * Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
 * 
 * Note:
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * Example 1:
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * Example 2:
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 */
 
2-D DP:

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1) return false;
        sum /= 2;
        
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        dp[0][0] = true;
        
        for (int i = 1; i < n+1; i++) 
            dp[i][0] = true;
            
        for (int j = 1; j < sum+1; j++) 
            dp[0][j] = false;
        
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < sum+1; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]) {
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
                }
            }
        }

        return dp[n][sum];
    }
};

1-D DP:

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1) return false;
        sum /= 2;
        
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < nums.size(); i++) 
            for (int j = sum; j > 0; j--) 
                if (j >= nums[i]) 
                    dp[j] = dp[j] || dp[j - nums[i]];

        return dp[sum];
    }
};
