class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) {
            return true;
        }

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (st.size()) {
                switch (s[i]) {
                    case ']':
                        if (st.top() == '[') {
                            st.pop();
                            continue;
                        }
                        break;
                    case '}':
                        if (st.top() == '{') {
                            st.pop();
                            continue;
                        }
                        break;
                    case ')':
                        if (st.top() == '(') {
                            st.pop();
                            continue;
                        }
                        break;

                }
            }
            st.push(s[i]);
        }

        return st.size() ? false : true;
        
    }
};
