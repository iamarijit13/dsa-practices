class Solution {
    unordered_set<string> uniques;
public:
    vector<vector<int>> permuteUniques(vector<int>& nums) {
        if (nums.empty()) return {{}};

        vector<int> te = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permuteUnique(te);
        vector<vector<int>> re;

        for (const auto& p : perms) {
            for (int i = 0; i <= p.size(); i++) {
                vector<int> pCopy = p;  
                pCopy.insert(pCopy.begin() + i, nums[0]);
                string s = toString(pCopy);
                if (uniques.count(s)) continue;
                uniques.insert(s);
                re.push_back(pCopy);
            }
        }
        return re;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> re;
        unordered_map<int, int> count;

        for (int &num : nums) {
            count[num]++;
        }
        vector<int> perm;
        
        auto backtrack = [&nums, &re, &count](auto &self, vector<int> &perm) {
            if (perm.size() == nums.size()) {
                re.push_back(perm);
                return;
            }

            for (auto &[num, cnt] : count) {
                if (cnt > 0) {
                    perm.push_back(num);
                    cnt--;
                    self(self, perm);
                    cnt++;
                    perm.pop_back();
                }
            }
        };
        backtrack(backtrack, perm);
        return re;
    }
private:
    string toString(vector<int> nums) {
        string re = "";
        for (int n : nums) {
            re += to_string(n) + ",";
        }
        return re;
    }
};