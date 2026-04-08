class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (auto& task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (auto& c : count) {
            if (c > 0) maxHeap.push(c);
        }

        int time = 0;
        queue<pair<int, int>> qu;
        while (!maxHeap.empty() || !qu.empty()) {
            time++;

            if (maxHeap.empty()) {
                time = qu.front().second;
            } else {
                int c = maxHeap.top() - 1;
                maxHeap.pop();
                if (c > 0) {
                    qu.push({c, time + n});
                }
            }

            if (!qu.empty() && qu.front().second == time) {
                maxHeap.push(qu.front().first);
                qu.pop();
            }
        }
        return time;
    }
};
