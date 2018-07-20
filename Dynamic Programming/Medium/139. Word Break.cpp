/* LeetCode 139. Word Break
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * The same word in the dictionary may be reused multiple times in the segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * Example 1:
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 * Example 2:
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 *              Note that you are allowed to reuse a dictionary word.
 * Example 3:
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 */
 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int ll = s.size();
        int dict = wordDict.size();
        vector<bool> dp(ll + 1, false);
        dp[0] = true;
        for (int i = 0; i <= ll; i++) {
            for (int j = 0; j < dict; j++) {
                if (dp[i]) {
                    string str = s.substr(i, wordDict[j].size());
                    if (str == wordDict[j]) {
                        dp[i + wordDict[j].size()] = true;
                    }
                }
            }
        }
        return dp[ll];
    }
};
