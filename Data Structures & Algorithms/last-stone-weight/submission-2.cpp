class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;

        for (auto stone : stones) {
            heap.push(stone);
        }

        while (heap.size() > 1) {
            int h1 = heap.top();
            heap.pop();
            int h2 = heap.top();
            heap.pop();

            if (h1 > h2) {
                heap.push(h1 - h2);
            }
        }

        return heap.size() > 0 ? heap.top() : 0;
    }
};
