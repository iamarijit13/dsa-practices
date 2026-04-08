class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> hash;

        for (int i = 0; i < order.size(); i++) {
            hash[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];

            for (int j = 0; j < w1.size(); j++) {
                if (j >= w2.size()) {
                    return false;
                }

                if (w1[j] != w2[j]) {
                    if (hash[w1[j]] > hash[w2[j]]) {
                        return false;
                    }
                    // continue;
                    break;
                }
            }
        }
        return true;
    }
};