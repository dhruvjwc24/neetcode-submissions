class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> track_row(9);
        vector<unordered_set<char>> track_col(9);
        vector<unordered_set<char>> track_blk(9);

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') { continue; }
                
                if (
                    track_row[r].count(ch) || // in row
                    track_col[c].count(ch) || // in col
                    track_blk[r/3*3+c/3].count(ch) // in blk
                    ) {
                        return false;
                    }
                
                track_row[r].insert(ch);
                track_col[c].insert(ch);
                track_blk[r/3*3+c/3].insert(ch);
            }
        }

        return true; 
    }
};
