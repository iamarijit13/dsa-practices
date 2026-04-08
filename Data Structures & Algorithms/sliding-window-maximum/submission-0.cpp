class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> re;
        // vector<int> re(n - k + 1);
        deque<int> q;
        int l = 0, r = 0;

        while (r < nums.size()) {
            while (!q.empty() && nums[q.back()] < nums[r]) {
                cout << q.back();
                q.pop_back();
            }
            q.push_back(r);

            if (l > q.front()) {
                q.pop_front();
            }

            if ((r + 1) >= k) {
                // re[l] = 
                re.push_back(nums[q.front()]);
                l++;
            }
            r++;
        }
        return re;
    }
};
