class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        // cin.tie(nullptr);
        // cout.tie(nullptr);
        // ios_base::sync_with_stdio(false);

        int n = prices.size();
        if (n == 1) return 0;
        int currProfit = 0, minPrice = prices[0];
        for(int i = 1; i < n; i++)
        {
            minPrice = min(prices[i], prices[i-1]);
            currProfit = max(currProfit, currProfit + prices[i] - minPrice);
        }
        return currProfit;
    }
};