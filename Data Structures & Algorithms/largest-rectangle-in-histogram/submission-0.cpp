class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            if (st.empty()) {
                st.push({i, heights[i]});
            }

            if (!st.empty() && heights[i] >= st.top().second) {
                st.push({i, heights[i]});
            }

            while (!st.empty() && st.top().second > heights[i]) {
                maxArea = max(maxArea, st.top().second * (i - st.top().first));

                start = st.top().first;
                st.pop();
            }

            st.push({start, heights[i]});
        }

        int size = heights.size();

        while (!st.empty()) {
            maxArea = max(maxArea, (size - st.top().first) * st.top().second);
            st.pop();
        }

        return maxArea;
    }
};
