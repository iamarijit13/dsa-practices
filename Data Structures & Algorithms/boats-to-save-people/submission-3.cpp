class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boat = 0, l = 0, r = people.size() - 1;

        while (l <= r) {
            if (people[l] + people[r] <= limit) l++, r--, boat++;
            else r--, boat++;
        }
        return boat;
    }

    int numRescueBoatss(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boat = 0, l = 0, r = people.size() - 1;

        while (l <= r) {
            int remain = limit - people[r];
            r--, boat++;
            if (l <= r && remain >= people[l]) l++;
        }
        return boat;
    }
};