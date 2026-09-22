class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> hash;

        for (int i = 0; i < s.size(); i++) {
            hash[s[i]] = i;
        }

        int size = 0, end = 0;
        vector<int> re;
        for (int i = 0; i < s.size(); i++) {
            size++;
            end = max(end, hash[s[i]]);

            if (end == i) {
                re.push_back(size);
                size = 0;
            }
        }
        return re;
    }
};
