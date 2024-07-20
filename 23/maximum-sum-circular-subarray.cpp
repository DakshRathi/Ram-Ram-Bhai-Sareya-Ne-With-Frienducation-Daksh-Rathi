class Solution {
public:
    int kadane(vector<int>& nums) {
        int curSum = 0, maxSum = INT_MIN;
        for (int num : nums) {
            curSum = max(curSum + num, num);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int nonWrapSum = kadane(nums);
        
        int totalSum = 0;
        for (int& num : nums) {
            totalSum += num;
            num = -num;
        }
        
        int invertedKadane = kadane(nums);
        int wrapSum = totalSum + invertedKadane;
        
        if (wrapSum == 0) return nonWrapSum;
        
        return max(nonWrapSum, wrapSum);
    }
};