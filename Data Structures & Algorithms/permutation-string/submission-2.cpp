class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> count1(26, 0), count2(26, 0);
        int matches = 0;

        for (int i = 0; i < s1.size(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count1[i] == count2[i]) matches++;
        }

        int l = 0;
        for (int r = s1.size(); r < s2.size(); r++) {
            if (matches == 26) return true;

            int index = s2[r] - 'a';
            count2[index]++;
            if (count2[index] == count1[index]) matches++;
            else if ((count1[index] + 1  == count2[index])) matches--;
            
            index = s2[l] - 'a';
            count2[index]--;
            if (count2[index] == count1[index]) matches++;
            else if (count1[index] - 1 == count2[index]) matches--;
            l++;
        }
        return matches == 26;
    }
};
