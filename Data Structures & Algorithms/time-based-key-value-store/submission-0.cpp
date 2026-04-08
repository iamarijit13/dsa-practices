class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> values = store[key];
        int left = 0, right = values.size() - 1;
        string re = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (values[mid].first <= timestamp) {
                re = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return re;
    }
};
