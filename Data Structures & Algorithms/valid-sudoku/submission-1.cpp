class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> track_row(9);
        vector<unordered_set<char>> track_col(9);
        vector<unordered_set<char>> track_block(9);

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') { continue; }
                auto it = track_row[r].find(ch);
                if (it == track_row[r].end()) {
                    track_row[r].insert(ch);
                } else { return false; }

                it = track_col[c].find(ch);
                if (it == track_col[c].end()) {
                    track_col[c].insert(ch);
                } else { return false; }

                it = track_block[r/3 * 3 + c/3].find(ch);
                if (it == track_block[r/3 * 3 + c/3].end()) {
                    track_block[r/3 * 3 + c/3].insert(ch);
                } else { return false; }
            }
        }

        return true; 
    }
};
