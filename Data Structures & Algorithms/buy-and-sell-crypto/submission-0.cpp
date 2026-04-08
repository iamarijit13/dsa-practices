class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = l + 1, maxProfit = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            } else {
                l = r;
            }

            ++r;
        }
        
        return maxProfit;
    }
};
