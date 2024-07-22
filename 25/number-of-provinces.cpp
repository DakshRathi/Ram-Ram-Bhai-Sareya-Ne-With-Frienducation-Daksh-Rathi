class Solution {
public:
void dfs(int i, vector<bool>& visited, vector<vector<int>> &connected)
{
    visited[i]=true;

    for(int j=0; j<connected.size(); j++)
    {
        if(connected[i][j]==1 && visited[j]==false)
        dfs(j, visited, connected);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<bool>visited(n, false);
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==false)
            {
                dfs(i, visited, isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};