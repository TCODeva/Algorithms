/* LeetCode 20. Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * Input: "()"
 * Output: true
 * Example 2:
 * 
 * Input: "()[]{}"
 * Output: true
 * Example 3:
 * 
 * Input: "(]"
 * Output: false
 * Example 4:
 * 
 * Input: "([)]"
 * Output: false
 * Example 5:
 * 
 * Input: "{[]}"
 * Output: true
 */
 
class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                    check.push(')');
                    break;
                case '[':
                    check.push(']');
                    break;
                case '{':
                    check.push('}');
                    break;
                default:
                    if (check.empty() || check.top() != s[i])
                        return false;
                    check.pop();
                    break;
            }
        }
        return check.empty();
    }
};
