/* LeetCode 10. Regular Expression Matching
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like . or *.
 * Example 1:
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * Example 2:
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * Example 3:
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * Example 4:
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
 * Example 5:
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 */
 
Recursive:

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

        if (p.size() >= 2 && p[1] == '*') {
            return (isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
        } else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

/* 1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1];
 * 2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
 * 3, If p.charAt(j) == '*': 
 *    here are two sub conditions:
 *                1   if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  in this case, a* only counts as empty
 *                2   if p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.':
 *                               dp[i][j] = dp[i-1][j]    in this case, a* counts as multiple a 
 *                            or dp[i][j] = dp[i][j-1]    in this case, a* counts as single a
 *                            or dp[i][j] = dp[i][j-2]    in this case, a* counts as empty
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        int lens = s.size(), lenp = p.size();
        vector<vector<bool>> dp(lens+1, vector<bool>(lenp+1, false));
        dp[0][0] = true;
        for (int i = 0; i < lenp; i++) {
            if (p[i] == '*' && dp[0][i-1]) {
                dp[0][i+1] = true;
            }
        }
        for (int i = 0 ; i < lens; i++) {
            for (int j = 0; j < lenp; j++) {
                if (p[j] == '.') {
                    dp[i+1][j+1] = dp[i][j];
                }
                if (p[j] == s[i]) {
                    dp[i+1][j+1] = dp[i][j];
                }
                if (p[j] == '*') {
                    if (p[j-1] != s[i] && p[j-1] != '.') {
                        dp[i+1][j+1] = dp[i+1][j-1];
                    } else {
                        dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
                    }
                }
            }
        }
        return dp[lens][lenp];
    }
};

/* This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:
 * 
 * P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
 * P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
 * P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
 * Putting these together, we will have the following code.
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length(); 
        vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        return dp[m][n];
    }
};
