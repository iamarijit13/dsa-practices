class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (char c : s) {
            // if (c == '[') continue;
            if (c == ']') {
                string current = "";
                while (!st.empty() && !(isNumber(st.top()) || st.top() == "[")) {
                    current = st.top() + current;
                    st.pop();
                }
                if (!st.empty() && st.top() == "[") st.pop();
                if (!st.empty()) {
                    string num = "";
                    while (!st.empty() && isNumber(st.top())) {
                        num = st.top() + num;
                        st.pop();
                    }
                    int n = stoi(num);
                    cout << n << endl;
                    if (!st.empty() && st.top() == "[") st.pop();
                    // st.pop();
                    string g = current;
                    current = "";
                    for (int i = 0; i < n; i++) {
                        current += g;
                    }
                }
                cout << current << endl;
                st.push(current);
            } else {
                st.push(string(1, c));
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }

private:
    bool isNumber(string s) {
        return all_of(s.begin(), s.end(), ::isdigit);
    }
};