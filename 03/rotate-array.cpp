class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);
        
        int s = nums.size();
        k %= s;
        if(s == k) return;
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(),nums.end());
    }
};