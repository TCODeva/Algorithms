/* LeetCode 413. Arithmetic Slices
 * A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 * 
 * For example, these are arithmetic sequence:
 * 
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * The following sequence is not arithmetic.
 * 
 * 1, 1, 2, 5, 7
 * 
 * A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
 * 
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 * A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
 * 
 * The function should return the number of arithmetic slices in the array A.
 * 
 * 
 * Example:
 * 
 * A = [1, 2, 3, 4]
 * 
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int i = 0, j = 1, dis = A[1] - A[0], count = 0;
        while (i < A.size()-2 && j < A.size()) {
            while (A[j] - A[j-1] == dis && j < A.size()) 
                j++;
            if (j - i > 2) 
                count = count + (j - i - 1) * (j - i - 2) / 2;
            dis = A[j] - A[j-1];
            i = j - 1;
        }
        return count;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int curr = 0, sum = 0;
        for (int i = 2; i < A.size(); i++)
        if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
            curr += 1;
            sum += curr;
        } else {
            curr = 0;
        }
    return sum;
    }
};
