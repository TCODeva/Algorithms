/* LeetCode 300. Longest Increasing Subsequence
 * Given an unsorted array of integers, find the length of longest increasing subsequence.
 * 
 * Example:
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
 * Note:
 * 
 * There may be more than one LIS combination, it is only necessary for you to return the length.
 * Your algorithm should run in O(n2) complexity.
 * Follow up: Could you improve it to O(n log n) time complexity?
 */
 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    
        int n = nums.size(), maxLen = 1;
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; i++) {
            int j = i - 1, tempMax = 1;
            while (j >= 0) {
                if (nums[i] > nums[j]) 
                    tempMax = max(tempMax, dp[j] + 1);
                if (tempMax > j) break;
                j--;
            }
            dp[i] = tempMax;
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;
        
    }
};

