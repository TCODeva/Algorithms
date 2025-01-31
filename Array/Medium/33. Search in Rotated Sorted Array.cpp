/* LeetCode 33. Search in Rotated Sorted Array
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 */
 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n-1, mid = 0; 
        while (low < high) {
            mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) low = mid+1;
            else high = mid;
        }
        int root = low;
        low = 0; high = n-1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            int realmid = (mid + root) % n;
            if (nums[realmid] == target) return realmid;
            if (nums[realmid] > target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};
