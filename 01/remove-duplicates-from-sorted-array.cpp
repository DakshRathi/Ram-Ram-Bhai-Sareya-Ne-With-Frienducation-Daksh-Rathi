class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0,k=1;
        while(i<nums.size()-1)
        {
            if(nums[i]!=nums[i+1])
            {
                nums[k]=nums[i+1];
                k++;
            }
            i++;
        }
        return k;
    }
};