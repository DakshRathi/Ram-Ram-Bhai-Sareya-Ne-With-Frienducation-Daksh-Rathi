class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);
        
        int index = nums[0], s = nums.size();
        for(int i = 0; i < s; i++)
        {
            if(index >= s - 1) return true;
            if(index == i && nums[i] == 0) return false;
            if(i + nums[i] > index) index = nums[i] + i; 
        }
        return true;
    }
};