/* LeetCode 40. Combination Sum II
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * Example 1:
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 *   [1, 7],
 *   [1, 2, 5],
 *   [2, 6],
 *   [1, 1, 6]
 * ]
 * Example 2:
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 *   [1,2,2],
 *   [5]
 * ]
 */
 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backTracking(res, cur, candidates, target, 0);
        return res;
    }
    
private:
    void backTracking(vector<vector<int>>& res, vector<int>& cur, vector<int>& candidates, int target, int start) {
        if (target < 0) return;       
        if (target == 0) res.push_back(cur);
        if (target >= candidates[start]) 
            for (int i = start; i < candidates.size(); i++) {
                if (i > start && candidates[i] == candidates[i-1]) continue;
                cur.push_back(candidates[i]);
                backTracking(res, cur, candidates, target - candidates[i], i + 1);
                cur.pop_back(); //remove the last one which overflows
            }
    }
};
