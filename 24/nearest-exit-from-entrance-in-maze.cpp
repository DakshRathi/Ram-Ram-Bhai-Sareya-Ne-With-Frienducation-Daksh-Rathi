class Solution {
public:
    struct customDataStruct
    {
        int x , y , dist;
    };

    bool isValid(vector<vector<char>>& maze, vector<vector<bool>> &vis, int i, int j, int n, int m)
    {
        if(i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && maze[i][j] == '.') return true;
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);

        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int x = entrance[0] , y = entrance[1];
        
        queue<customDataStruct> q;
        int min_dist = 1e9;
        q.push({x , y , 0});
        vis[x][y] = true;

        while(!q.empty())
        {
            customDataStruct cur = q.front();
            q.pop();
            int i = cur.x , j = cur.y , dist = cur.dist;
            if(((i == 0 || i == n - 1) || (j == 0 || j == m - 1)) && maze[i][j] == '.')
            {
                if(i != x || j != y)
                {
                    min_dist = dist;
                    break;
                }
            }

            for (int k = 0; k < 4; k++)
            {
                int ti = i + dx[k] , tj = j + dy[k];
                if (isValid(maze, vis, ti, tj, n, m))
                {
                    vis[ti][tj] = true;
                    q.push({ti , tj , dist + 1});
                }
            }
        }

        if (min_dist == 1e9) return -1;
        else return min_dist;
    }
};