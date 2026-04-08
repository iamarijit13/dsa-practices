class Solution {
public:
    static bool sortByValue(const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> topk;

        for (auto x : nums) {
            if (m.find(x) != m.end()) {
                m[x]++;
            }

            m.insert({x, 1});
        }

        vector<pair<int, int>> mapVector(m.begin(), m.end());
        sort(mapVector.begin(), mapVector.end(), sortByValue); 

        int i = 0;

        while (k--) {
            topk.push_back(mapVector[i].first);
            i++;
        }

        return topk;
    }
};
