class Twitter {
    int count;
    unordered_map<int, vector<vector<int>>> tweetMap;
    unordered_map<int, set<int>> followMap;
public:
    Twitter() {
       this -> count = 0; 
    }
    
    void postTweet(int userId, int tweetId) {
        this -> tweetMap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minHeap(compare);
        followMap[userId].insert(userId);
        
        for (int followeeId : followMap[userId]) {
            if (tweetMap.count(followeeId)) {
                const vector<vector<int>>& tweets = tweetMap[followeeId];
                int index = tweets.size() - 1;
                minHeap.push({tweets[index][0], tweets[index][1], followeeId, index});
            }
        }

        while (!minHeap.empty() && res.size() < 10) {
            vector<int> cur = minHeap.top();
            minHeap.pop();
            res.push_back(cur[1]);
            int index = cur[3];
            if (index > 0) {
                const vector<int>& tweet = tweetMap[cur[2]][index - 1];
                minHeap.push({tweet[0], tweet[1], cur[2], index - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        this -> followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        this -> followMap[followerId].erase(followeeId);
    }
};
