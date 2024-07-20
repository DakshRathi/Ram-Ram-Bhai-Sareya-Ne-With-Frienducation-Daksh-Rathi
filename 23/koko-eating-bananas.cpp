class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (piles.size() == 1) return (piles[0] / h + (piles[0] % h != 0));

        int low=1;
        int high= *max_element(piles.begin(),piles.end());

        while (low <= high)
        {
            int mid = (high + low)/2;
            long long ans = 0;
            for (auto i : piles) ans += (i/mid)+(i%mid != 0);
            if(ans<=h) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};