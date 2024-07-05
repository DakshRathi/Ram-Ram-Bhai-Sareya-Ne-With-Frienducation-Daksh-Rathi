class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(auto n : nums)
        {
            if(s.find(n - 1) == s.end())
            {
                int len = 1;
                while(s.find(n + len) != s.end()) len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};