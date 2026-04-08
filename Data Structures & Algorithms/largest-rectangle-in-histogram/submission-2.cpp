class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!st.empty() && st.top().second > heights[i]) {
                maxArea = max(maxArea, st.top().second * (i - st.top().first));
                start = st.top().first;
                st.pop();
            }

            st.push({start, heights[i]});
        }

        while (!st.empty()) {
            maxArea = std::max(maxArea, st.top().second * ((int)heights.size() - st.top().first));
            st.pop();
        }

        return maxArea;        
    }
};
