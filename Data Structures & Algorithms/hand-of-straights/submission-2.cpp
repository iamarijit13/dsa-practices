class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> hash;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int h : hand) {
            if (hash.count(h)) {
                hash[h]++;
            } else {
                hash[h] = 1;
                q.push(h);
            }
        }

        while (!q.empty()) {
            int min = q.top();
            int next = min;
            for (int i = 1; i <= groupSize; i++) {
                if (hash[next] > 0) {
                    hash[next]--;
                    if (hash[next] == 0) q.pop();
                } else {
                    return false;
                }
                next++;
            }
        }

        return true;
    }
};
