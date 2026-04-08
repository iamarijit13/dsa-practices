class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxLeft = height[l], maxRight = height[r];
        int re = 0;

        while (l < r) {
            if (maxLeft < maxRight) {
                l++;
                maxLeft = max(maxLeft, height[l]);
                re += maxLeft - height[l]; 
            } else {
                r--;
                maxRight = max(maxRight, height[r]);
                re += maxRight - height[r];
            }
        }
        return re;
    }
};
