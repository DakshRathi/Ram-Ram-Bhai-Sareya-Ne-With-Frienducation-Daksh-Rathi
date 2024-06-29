class Solution {
public:
    int jump(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);
        
        int near = 0, far = 0, jumps = 0;
        while(far < nums.size() - 1)
        {
            int maxIdx = 0;
            for(int i = near; i <= far; i++) maxIdx = max(maxIdx, nums[i] + i);
            near = far;
            far = maxIdx;
            jumps++;
        }
        return jumps;
    }
};