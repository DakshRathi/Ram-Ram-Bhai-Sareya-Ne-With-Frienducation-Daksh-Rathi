class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Moore Voting Algorithm
        int count = 1;
        int candidate = nums[0];
        
        for (int i = 1 ; i < nums.size() && count <= nums.size()/2 ; i++)
        {
            if (count == 0) {
                candidate = nums[i];
            }
            
            if (nums[i] == candidate) count++;
            else count--;
        }
        
        return candidate;
    }
};