/* LeetCode 44. Wildcard Matching
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like ? or *.
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
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 * Example 3:
 * 
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 * Example 4:
 * 
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
 * Example 5:
 * 
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 */
 
class Solution {
public:
    bool isMatch(string str, string pattern) {
        int s = 0, p = 0, match = 0, starIdx = -1;            
        while (s < str.size()) {
            // advancing both pointers
            if (p < pattern.size()  && (pattern[p] == '?' || str[s] == pattern[p])) {
                s++;
                p++;
            }
            // * found, only advancing pattern pointer
            else if (p < pattern.size() && pattern[p] == '*') {
                starIdx = p;
                match = s;
                p++;
            }
            // last pattern pointer was *, advancing string pointer
            else if (starIdx != -1) {
                p = starIdx + 1;
                match++;
                s = match;
            }
            //current pattern pointer is not star, last patter pointer was not *
            //characters do not match
            else return false;
        }
        
        //check for remaining characters in pattern
        while (p < pattern.size() && pattern[p] == '*')
            p++;
        
        return p == pattern.size();
    }
};
