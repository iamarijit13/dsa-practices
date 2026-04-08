class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        this -> st.push(val);
    }
    
    void pop() {
        this -> st.pop();
    }
    
    int top() {
        return this -> st.top();
    }
    
    int getMin() {
        stack<int> te;
        int minimum = st.top();

        while (!st.empty()) {
            minimum = min(st.top(), minimum);

            te.push(st.top());
            st.pop();
        }

        while (!te.empty()) {
            st.push(te.top());
            te.pop();
        }

        return minimum;
    }
};
