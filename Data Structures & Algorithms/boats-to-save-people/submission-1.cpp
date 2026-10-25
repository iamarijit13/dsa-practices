class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0;
        int l = 0, r = people.size() - 1;

        while (l <= r) {
            int remain = limit - people[r];
            r--;
            boats += 1;
            if (l <= r && remain >= people[l]) l++;
        }
        return boats;
    }
};