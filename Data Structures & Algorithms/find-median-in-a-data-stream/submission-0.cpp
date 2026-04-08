class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> largeHeap;
    priority_queue<int, vector<int>, less<int>> smallHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        this -> smallHeap.push(num);

        if (! this -> largeHeap.empty() 
            && this -> smallHeap.top() 
            > this -> largeHeap.top()) {
            int top = smallHeap.top();
            this -> smallHeap.pop();
            this -> largeHeap.push(top);
        }

        if (this -> smallHeap.size() > this -> largeHeap.size() + 1) {
            this -> largeHeap.push(smallHeap.top());
            this -> smallHeap.pop();
        }

        if (this -> smallHeap.size() + 1 < this -> largeHeap.size()) {
            this -> smallHeap.push(largeHeap.top());
            this -> largeHeap.pop();
        }
    }
    
    double findMedian() {
        if (this -> smallHeap.size() == this -> largeHeap.size()) {
            return ((smallHeap.top() + largeHeap.top()) / 2.0); 
        } else if (this -> smallHeap.size() > this -> largeHeap.size()) {
            return this -> smallHeap.top();
        } else {
            return this -> largeHeap.top();
        }
    }
};
