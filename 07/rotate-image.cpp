class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);

        int row = matrix.size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < i; j++) swap(matrix[i][j], matrix[j][i]);
        }
        for(int i = 0; i < row; i++) reverse(matrix[i].begin(), matrix[i].end());
        return;
    }
};