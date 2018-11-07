/* LeetCode 32. Longest Valid Parentheses
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * Example 2:
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 */
 
// DP:

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};

// stack:

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> stack;
        stack.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    res = max(res, i - stack.top());
                }
            }
        }
        return res;
    }
};

/* In this approach, we make use of two counters leftleft and rightright. First, we start traversing the string 
 * from the left towards the right and for every \text{‘(’}‘(’ encountered, we increment the leftleft counter and 
 * for every \text{‘)’}‘)’ encountered, we increment the rightright counter. Whenever leftleft becomes equal to 
 * rightright, we calculate the length of the current valid string and keep track of maximum length substring 
 * found so far. If rightright becomes greater than leftleft we reset leftleft and rightright to 00.
 * 
 * Next, we start traversing the string from right to left and similar procedure is applied.
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int left = 0, right = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) res = max(res, 2 * right);
            else if (right >= left) left = right = 0;
        }
        
        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) res = max(res, 2 * left);
            else if (left >= right) left = right = 0;
        }
        return res;
    }
};
