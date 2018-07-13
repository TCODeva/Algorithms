/* LeetCode 368. Largest Divisible Subset
 * Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
 * 
 * If there are multiple solutions, return any subset is fine.
 * 
 * Example 1:
 * 
 * nums: [1,2,3]
 * 
 * Result: [1,2] (of course, [1,3] will also be ok)
 * Example 2:
 * 
 * nums: [1,2,4,8]
 * 
 * Result: [1,2,4,8]
 */
 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0) {
            vector<int> set;
            return set;
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        int maxSet = 1, sign = 0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j]  == 0 && dp[i][0] < dp[j][0] + 1) {
                    dp[i][0] = dp[j][0] + 1;
                    dp[i][1] = j;
                }
            }
            if (maxSet < dp[i][0]) {
                maxSet = dp[i][0];
                sign = i;
            }
        }

        vector<int> set(maxSet, 0);
        int k = maxSet;
        while (sign != -1) {
            set[--k] = nums[sign];
            sign = dp[sign][1];
        }
        return set;
    }
};
