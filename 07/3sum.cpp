class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);

        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<vector<int>> ans;
        if(nums[0] > 0 || nums[sz - 1] < 0) return ans;
        set<vector<int>> s;
        
        for(int i = 0; i < sz - 2; i++)
        {
            if(nums[i] > 0) break;
            int j = i + 1;
            int k = sz - 1;
            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum > 0) k--;
                else j++;
            }
        }
        for(auto triplet : s) ans.push_back(triplet);
        return ans;
    }
};