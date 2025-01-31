/* LeetCode 647. Palindromic Substrings
 * Given a string, your task is to count how many palindromic substrings in this string.
 * 
 * The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 * 
 * Example 1:
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * Example 2:
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * Note:
 * The input string length won't exceed 1000.
 */
 
class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 0) return 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++) 
            count = count + test(s,i,i) + test(s,i,i+1); 
        return count;
    }
    
    int test(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;right++;count++;
        }
        return count;
    }
};
