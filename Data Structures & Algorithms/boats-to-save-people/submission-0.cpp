class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0, l = 0, r = people.size() - 1;

        while (l <= r) {
            int remaining = limit - people[r];
            r -= 1;
            res += 1;

            if (remaining >= people[l]) {
                l++;
            }
        }
        return res;
    }
};