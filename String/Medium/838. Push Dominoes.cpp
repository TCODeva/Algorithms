/* LeetCode 838. Push Dominoes
 * There are N dominoes in a line, and we place each domino vertically upright.
 * 
 * In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
 * 
 * 
 * 
 * After each second, each domino that is falling to the left pushes the adjacent domino on the left.
 * 
 * Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
 * 
 * When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
 * 
 * For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
 * 
 * Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.
 * 
 * Return a string representing the final state. 
 * 
 * Example 1:
 * 
 * Input: ".L.R...LR..L.."
 * Output: "LL.RR.LLRRLL.."
 * Example 2:
 * 
 * Input: "RR.L"
 * Output: "RR.L"
 * Explanation: The first domino expends no additional force on the second domino.
 * Note:
 * 
 * 0 <= N <= 10^5
 * String dominoes contains only 'L', 'R' and '.'
 */
 
class Solution {
public:
    string pushDominoes(string dominoes) {
        int i = 0, j = 1, n = dominoes.size();
        while (j < dominoes.size()) {
            
            while (dominoes[j] == '.' && j < n) j++;
            if (j == n) j--;
            
            if (dominoes[i] == '.') {
                if (dominoes[j] == 'L') 
                    for (int k = i; k < j; k++)
                        dominoes[k] = 'L';             
            }
            
            if (dominoes[i] == 'L') {
                if (dominoes[j] == 'L')
                    for (int k = i; k < j; k++)
                        dominoes[k] = 'L';
            }
            
            if (dominoes[i] == 'R') {
                if (dominoes[j] == 'L') {
                    int head = i + 1, tail = j - 1;
                    while (head < tail) {
                        dominoes[head++] = 'R';
                        dominoes[tail--] = 'L';
                    }
                } else {
                    for (int k = i; k < j; k++)
                        dominoes[k] = 'R';
                    if (dominoes[j] == '.') dominoes[j] = 'R';
                }
            }
            
            i = j;
            j++;
        }
                
        return dominoes;
    }
};
