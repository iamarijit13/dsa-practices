class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> good;

        for (vector<int> &triplet : triplets) {
            // for (int i = 0; i < target.size(); i++) {
            //     if (triplet[i] > target[i]) continue;
            // }
            
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) continue;

            for (int i = 0; i < target.size(); i++) {
                if (triplet[i] == target[i]) good.insert(i);
            }
        }

        return good.size() == target.size() ? true : false;
    }
};
