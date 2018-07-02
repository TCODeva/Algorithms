/* LeetCode 357. Count Numbers with Unique Digits
 * Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
 * 
 * Example:
 * Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 */
 
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int sum = 10;
        while (n > 1) {
            if (n > 10) n = 10;
            int i = 9;
            for (int j = 9; j > 10 - n; j--)
                i *= j;
            sum += i;
            n--;
        }
        return sum;
    }
};
