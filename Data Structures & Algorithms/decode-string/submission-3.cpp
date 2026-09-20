class Solution {
   public:
    string decodeStrings(string s) {
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

    string decodeString(string s) {
        vector<string> st;

        for (char c : s) {
            if (c == ']') {
                string current = "";
                while (!st.empty() && st.back() != "[") {
                    current = st.back() + current;
                    st.pop_back();
                }
                if (!st.empty()) st.pop_back();
                string num = "";
                while (!st.empty() && isNumber(st.back())) {
                    num = st.back() + num;
                    st.pop_back();
                }
                int n = stoi(num);
                string latest = "";
                for (int i = 0; i < n; i++) {
                    latest += current;
                }
                st.push_back(latest);
            } else {
                st.push_back(string(1, c));
            }
        }

        string re = "";
        for (string s : st) {
            re += s;
        }
        return re;
    }

   private:
    bool isNumber(string s) { return all_of(s.begin(), s.end(), ::isdigit); }
};