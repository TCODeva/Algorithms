/* LeetCode 5. Longest Palindromic Substring
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * Example 2:
 * 
 * Input: "cbbd"
 * Output: "bb"
 */
 
class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0, currLen = 0, head = 0;
        for (int i = 0; i < s.size(); i++) {
            currLen = max(test(s, i, i), test(s, i, i+1));
            if (currLen > maxLen) {
                head = i - (currLen - 1) / 2;
                maxLen = currLen;
            }
        }
        return s.substr(head, maxLen);
    }
        
    int test (string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;right++;
        }
        return right - left - 1;
    }
};
