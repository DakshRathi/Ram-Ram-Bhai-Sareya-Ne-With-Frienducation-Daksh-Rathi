class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // Character frequency check
        if (!canForm(board, word)) return false;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) return false;
        
        char temp = board[i][j];
        board[i][j] = '*'; // Mark as visited
        bool found = dfs(board, word, i + 1, j, k + 1) ||
                     dfs(board, word, i - 1, j, k + 1) ||
                     dfs(board, word, i, j + 1, k + 1) ||
                     dfs(board, word, i, j - 1, k + 1);
        board[i][j] = temp; // Reset after visiting
        
        return found;
    }

    bool canForm(vector<vector<char>>& board, string& word) {
        unordered_map<char, int> boardFreq, wordFreq;
        for (const auto& row : board) {
            for (const auto& ch : row) {
                boardFreq[ch]++;
            }
        }
        for (const auto& ch : word) {
            wordFreq[ch]++;
        }
        for (const auto& [ch, freq] : wordFreq) {
            if (boardFreq[ch] < freq) return false;
        }
        return true;
    }
};