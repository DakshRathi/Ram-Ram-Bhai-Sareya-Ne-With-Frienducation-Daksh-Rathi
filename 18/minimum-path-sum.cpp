class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);

        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int i = rows - 2; i >= 0; i--) grid[i][cols - 1] +=  grid[i + 1][cols - 1];
        for (int j = cols - 2; j >= 0; j--) grid[rows - 1][j] +=  grid[rows - 1][j + 1];

        for (int i = rows - 2; i >= 0; i--)
        {
            for (int j = cols - 2; j >= 0; j--)
            {
                int down = grid[i + 1][j];
                int right = grid[i][j + 1];
                grid[i][j] += min(down, right);
            }
        }
        
        return grid[0][0];
    }
};