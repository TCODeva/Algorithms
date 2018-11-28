/* LeetCode 42. Trapping Rain Water
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 * 
 * Example:
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */
 
DP:

class Solution {
public:
    int trap(vector<int>& height) {
        
        int res = 0, size = height.size();
        if (size == 0) return res;
        vector<int> left_max(size), right_max(size);
        
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) 
            left_max[i] = max(height[i], left_max[i - 1]);
        
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) 
            right_max[i] = max(height[i], right_max[i + 1]);
        
        for (int i = 1; i < size - 1; i++)
            res += min(left_max[i], right_max[i]) - height[i];
        
        return res;
    }
};

Stack:

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                res += distance * bounded_height;
            }
            st.push(current++);
        }
        return res;
    }
};

Two-Points:

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : res += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : res += (right_max - height[right]);
                --right;
            }
        }
        return res;
    }
};
