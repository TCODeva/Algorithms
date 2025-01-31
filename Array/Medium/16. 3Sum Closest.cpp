/* LeetCode 16. 3Sum Closest
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), res = nums[0] + nums[1] + nums[n-1];;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++) {
            int low = i+1, high = n-1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == target) return target;
                if (abs(sum-target) < abs(res-target)) res = sum;
                if (sum > target) high--;
                else low++;
            }
        }
        return res;
    }
};
