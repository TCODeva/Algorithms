/* LeetCode 15. 3Sum
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 */
 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i]*3 > 0) break;
            if (nums[i]+2*nums[n-1] < 0) continue;
            int head = i+1, tail = n-1;
            while (head < tail) {
                if (nums[head] + nums[tail] + nums[i] == 0) {
                    res.push_back({nums[i],nums[head],nums[tail]});
                    while (head < tail && nums[head] == nums[head+1]) head++;
                    while (head < tail && nums[tail] == nums[tail-1]) tail--;
                    head++; tail--;
                } else if (nums[head] + nums[tail] + nums[i] < 0) {
                    head++;
                } else {
                    tail--;
                }
            }
        }
        return res;
    }
};
