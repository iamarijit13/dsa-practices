class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> re(temperatures.size());
        st.push({0, temperatures[0]});

        for (int i = 1; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > st.top().second) {
                re[st.top().first] = i - st.top().first;
                st.pop();
            }

            st.push({i, temperatures[i]});
        }

        while (!st.empty()) {
            re[st.top().first] = 0;
            st.pop();
        }

        return re;
    }
};
