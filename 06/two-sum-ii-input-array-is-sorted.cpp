class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);
        
        int left = 0, right = numbers.size() - 1;
        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
            if(sum == target) return {left + 1, right + 1};
            else if(sum < target) left++;
            else right--;
        }
        return {-1, -1};
    }
};