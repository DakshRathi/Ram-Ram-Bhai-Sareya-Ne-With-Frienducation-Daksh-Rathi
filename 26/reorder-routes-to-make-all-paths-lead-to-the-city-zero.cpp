class Solution {
public:
    int ans = 0;
    void dfs(unordered_map<int,vector<int>>&mp ,unordered_map<int,bool>&vis,int m)
    {
        vis[m]=true;
        for(auto i:mp[m])
        {
            if(i>=0)
            {
                if(!vis[i]) dfs(mp,vis,i);
            }
            else
            {
                i=abs(i);
                if(!vis[i])
                {   
                    ans++;
                    dfs(mp,vis,i);
                }
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int s = connections.size();
        unordered_map<int, vector<int>> mp;
        unordered_map<int, bool> vis;
        for(int i=0;i<s;i++)
        {
            mp[connections[i][1]].push_back(connections[i][0]);
            mp[connections[i][0]].push_back(-connections[i][1]);
        }
        dfs(mp,vis,0);
        if(ans == 0) return ans;
        return ans;
    }
};