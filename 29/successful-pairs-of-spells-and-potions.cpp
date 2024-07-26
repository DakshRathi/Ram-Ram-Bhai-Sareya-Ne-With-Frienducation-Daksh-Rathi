class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        vector<int> ans;
        sort(potions.begin(), potions.end());

        int n = potions.size();
        int lower = 0, higher = n - 1,index;
        long long temp ;
        for (int i = 0; i < spells.size(); i++)
        {
            temp= spells[i];
            if (temp * potions[n - 1] < success)
            {
                ans.push_back(0);
                continue;
            }
            lower = 0, higher = n - 1;
            while (lower <higher)
            {
                index = (lower + higher)/2;

                if((long long)(temp * potions[index]) < success) lower = index + 1;
                else higher = index;
            }
            ans.push_back(n-lower);
        }
        return ans;
    }
};