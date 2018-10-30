/* LeetCode 22. Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * 
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 */
 
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backString(res,"",0,0,n);
        return res;
    }
    
private:
    void backString(vector<string>& res, string s, int open, int close, int n) {
        if (s.size() == 2*n) {
            res.push_back(s);
            return;
        }
        if (open < n) backString(res, s+"(", open+1, close, n);
        if (close < open) backString(res, s+")", open, close+1, n);
    }
};
