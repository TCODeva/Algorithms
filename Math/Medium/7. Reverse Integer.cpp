/* LeetCode 7. Reverse Integer
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * Input: 123
 * Output: 321
 * Example 2:
 * 
 * Input: -123
 * Output: -321
 * Example 3:
 * 
 * Input: 120
 * Output: 21
 * Note:
 * Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

class Solution {
public:
    int reverse(int x) {
        int n = abs(x);
        long res = 0;
        while (n > 0) {
            int c = n % 10;
            n /= 10;
            res = res * 10 + c;
        }
        res = x > 0 ? res : -res;
        if (res > INT_MAX || res < INT_MIN) res = 0;
        return res;
    }
};
