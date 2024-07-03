class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);
        
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> rows(row, 0);
        vector<int> cols(col, 0);
        
        // First pass: mark the rows and columns that need to be zeroed
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        
        // Second pass: set the rows to zero
        for (int i = 0; i < row; i++) {
            if (rows[i] == 1) {
                for (int j = 0; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Third pass: set the columns to zero
        for (int j = 0; j < col; j++) {
            if (cols[j] == 1) {
                for (int i = 0; i < row; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};