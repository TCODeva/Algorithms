/* LeetCode 47. Permutations II
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * 
 * Example:
 * 
 * Input: [1,1,2]
 * Output:
 * [
 *   [1,1,2],
 *   [1,2,1],
 *   [2,1,1]
 * ]
 */
 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> check(nums.size(), 0);
        vector<int> subList;
        backString(res, subList, nums, check);
        return res;
    }
    
private:
    void backString(vector<vector<int>>& res, vector<int>& subList, vector<int>& nums, vector<int>& check) {
        if (subList.size() == nums.size()) {
            res.push_back(subList);
            return;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (check[i] != 0 || i > 0 && nums[i] == nums[i-1] && check[i-1] == 0) continue; // make sure that the order of same value does not change
                subList.push_back(nums[i]);
                check[i] = 1;
                backString(res, subList, nums, check);
                subList.pop_back();
                check[i] = 0;
            }
        }
    }
};
