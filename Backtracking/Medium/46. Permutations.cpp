/* LeetCode 46. Permutations
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * Input: [1,2,3]
 * Output:
 * [
 *   [1,2,3],
 *   [1,3,2],
 *   [2,1,3],
 *   [2,3,1],
 *   [3,1,2],
 *   [3,2,1]
 * ]
 */
 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tempList;
        backtrack(res, tempList, nums);
        return res;
    }

private: 
    void backtrack(vector<vector<int>>& res, vector<int>& tempList, vector<int>& nums){
        if (tempList.size() == nums.size()) {
            res.push_back(tempList);
        } else {
            for (int i = 0; i < nums.size(); i++) { 
                if (find(tempList.begin(), tempList.end(), nums[i]) != tempList.end()) continue; 
                tempList.push_back(nums[i]);
                backtrack(res, tempList, nums);
                tempList.pop_back();
            }
        }
    }
};
