class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, maxleft = height[l], maxright = height[r], re = 0;

        while (l < r) {
            if (maxleft < maxright) {
                l++;
                maxleft = max(maxleft, height[l]);
                re += max(maxleft, height[l]) - height[l];
            } else if (maxleft > maxright) {
                r--;
                maxright = max(maxright, height[r]);
                re += max(maxright, height[r]) - height[r];
            } else {
                l++;
                maxleft = max(maxleft, height[l]);
                re += max(maxleft, height[l]) - height[l];
            }
        }

        return re;
    }
};
