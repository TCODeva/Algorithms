/* LeetCode 53. Maximum Subarray
 *
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0], totalSum = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            
            //Current max sum is either the current element OR current element + Previous Maximum subarray)
            currentSum = max(nums[i], currentSum+nums[i]); 
            
            //If the current maximum array sum is greater than the global total. Update it
            totalSum = max(totalSum, currentSum);
        }
        return totalSum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int dp[nums.size()];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp[i-1] > 0) 
                dp[i] = dp[i-1] + nums[i];
            else 
                dp[i] = nums[i];
            if (dp[i] > sum) 
                sum = dp[i];
        }
        return sum;
    }
};
