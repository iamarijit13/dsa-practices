class Solution {
public:
    string toStrings(char c) {
        stringstream ss;
        ss << c;

        return ss.str();
    }

    string encode(vector<string>& strs) {
        string re = "";

        for (auto s : strs) {
            re += to_string(s.size()) + "#" + s;
        }

        return re;
    }

    vector<string> decode(string s) {
        vector<string> re;
        int j = 0;
        cout << s;

        for (int i = 0; i < s.size(); i++) {
            j = i;

            while (s[j] != '#') {
                j++;
            }
            cout << s.substr(j - 1, j - i);
            // int le = stoi(toStrings(s[j - 1]));
            int le = stoi(s.substr(i, j - i));

            re.push_back(s.substr(j + 1, le));
            i = j + le;
        }

        return re;
    }
};
