class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = costs.size();
        multiset<vector<int>> ms;
        int temp = candidates, l = 0, r = n - 1;
        while (temp-- && l < n) ms.insert({costs[l], l++});
        temp = candidates;
        while (l <= r && temp--) ms.insert({costs[r], r--});
        long long res = 0;
        while (k--)
        {
            int curCost = (*ms.begin())[0], idx = (*ms.begin())[1];
            ms.erase(ms.begin());
            res += curCost;

            if (l <= r)
            {
                if(idx <= l) ms.insert({costs[l], l++});
                else ms.insert({costs[r], r--});
            }
        }
        return res;
    }
};