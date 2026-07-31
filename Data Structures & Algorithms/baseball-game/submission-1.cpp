class Solution {
public:
    int calPointsa(vector<string>& operations) {
        stack<int> st;
        int re = 0;

        for (string op : operations) {
            if (op == "+") {
                if (!st.empty() && st.size() >= 2) {
                    int p1 = st.top();
                    int p2 = st.top();
                    st.push(p1 + p2);
                }
            } else if (op == "D") {
                if (!st.empty()) {
                    int p1 = st.top();
                    st.push(p1 * 2);
                }
            } else if (op == "C") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(stoi(op));
            }
        }

        while (!st.empty()) {
            re += st.top();
            st.pop();
        }

        return re;
    }

    int calPoints(vector<string>& ops) {
        stack<int> stack;
        int res = 0;
        for (const string& op : ops) {
            if (op == "+") {
                int top = stack.top(); stack.pop();
                int newTop = top + stack.top();
                stack.push(top);
                stack.push(newTop);
                res += newTop;
            } else if (op == "D") {
                stack.push(2 * stack.top());
                res += stack.top();
            } else if (op == "C") {
                res -= stack.top();
                stack.pop();
            } else {
                stack.push(stoi(op));
                res += stack.top();
            }
        }
        return res;
    }
};