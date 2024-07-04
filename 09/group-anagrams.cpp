class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<string, vector<string>> ump;
        for(auto x: strs)
        {
            string word = x;
            sort(word.begin(), word.end());
            ump[word].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto x: ump) ans.push_back(x.second);
        return ans;
    }
};