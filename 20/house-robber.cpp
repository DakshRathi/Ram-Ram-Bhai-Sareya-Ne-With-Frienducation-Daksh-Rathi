class Solution {
public:
    int robbed(int ind, vector<int>& nums, vector<int>& dp)
    {
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int take = nums[ind] + robbed(ind-2,nums,dp);
        int notTake =  robbed(ind-1,nums,dp);
        return dp[ind] = max(take,notTake);
    }

    int rob(vector<int>& nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = nums.size();
        vector<int> dp(n,-1);
        return robbed(n-1,nums,dp);
    }
};