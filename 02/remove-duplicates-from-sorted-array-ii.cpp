class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int k = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(k == 1 || nums[k - 2] != nums[i]) nums[k++] = nums[i];
        }
        return k;
    }
};