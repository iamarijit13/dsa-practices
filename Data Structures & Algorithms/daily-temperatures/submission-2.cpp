class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st;

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > st.top().second) {
                pair<int, int> cur = st.top();
                st.pop();
                res[cur.first] = (i - cur.first);
            }
            st.push({i, temperatures[i]});
        }

        // while (!st.empty()) {
        //     st.pop();
        //     res.push_back(0);
        // }
        return res;
    }
};
