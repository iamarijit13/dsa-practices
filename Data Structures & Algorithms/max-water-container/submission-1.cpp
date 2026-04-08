class Solution {
public:

    // Brute Force Solution: 
    int maxAreas(vector<int>& heights) {
        int maxarea = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                int w = j - i;
                int h = min(heights[i], heights[j]);

                maxarea = max(maxarea, w * h);
            }
        }

        return maxarea;
    }

    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, maxarea = 0;

        while (l < r) {
            int weidth = r - l, height = min(heights[l], heights[r]);
            maxarea = max(maxarea, weidth * height);

            if (heights[l] < heights[r]) {
                l++;
            } else if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }

        return maxarea;
    }
};
