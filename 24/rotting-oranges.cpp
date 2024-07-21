class Solution {
public:
    struct customDataStruct
    {
        int x, y, time;
    };

    int orangesRotting(vector<vector<int>>& grid)
    {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        queue<customDataStruct> q;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int time = 0;

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(grid[row][col] == 2) q.push({row, col, 0});
            }
        }

        while (!q.empty())
        {
            int row = q.front().x;
            int col = q.front().y;
            int t = q.front().time;
            time = max(t, time);
            q.pop();

            vis[row][col] = true;

            for(auto dir : directions)
            {
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = true;
                    q.push({nrow, ncol, t + 1});
                    grid[nrow][ncol] = 2;
                }
            }
        }

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(grid[row][col] == 1) return -1;
            }
        }
        return time;
    }
};