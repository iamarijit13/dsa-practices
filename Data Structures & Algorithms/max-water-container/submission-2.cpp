class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int re = 0;

        while (l < r) {
            int maxArea = (r - l) * min(heights[l], heights[r]);
            re = max(re, maxArea);

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return re;
    }
};
