class FreqStack {
    unordered_map<int, int> count;
    unordered_map<int, stack<int>> stacks;
    int maxCount;
public:
    FreqStack() {
        maxCount = 0;
    }
    
    void push(int val) {
        int valueCount = ++count[val];
        if (valueCount > maxCount) {
            maxCount = valueCount;
            stacks[valueCount] = stack<int>();
        }
        stacks[valueCount].push(val);
    }
    
    int pop() {
        int result = stacks[maxCount].top();
        stacks[maxCount].pop();
        count[result]--;
        if (stacks[maxCount].empty()) maxCount--;
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */