class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        return binarySearch(piles, h, l, r, r);
    }

    int binarySearch(vector<int>& piles, int h, int l, int r, int re) {
        if (l > r) {
            return re;
        }

        int mid = (l + r) / 2;
        if (eatBananas(piles, h, mid)) {
            re = mid;
            binarySearch(piles, h, l, mid - 1, re);
        } else {
            binarySearch(piles, h, mid + 1, r, re);
        }
    }

    bool eatBananas(vector<int>& piles, int h, int k) {
        long long time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += ceil(static_cast<double>(piles[i]) / k);
        }

        return time <= h;
    }
};
