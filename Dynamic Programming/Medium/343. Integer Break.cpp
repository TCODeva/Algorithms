/* LeetCode 343. Integer Break
 * Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
 * 
 * For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 */
 
class Solution {
public:
    int integerBreak(int n) {
     
        if (n <= 3) return n-1;
        int i = 1;
     
        while (n > 4) {
            i *= 3;
            n -= 3;
        }
     
        return i * n;
    }
};
