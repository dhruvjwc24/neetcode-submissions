class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size(); int numCols = matrix[0].size();

        int left = 0; int right = numRows * numCols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            pair<int, int> midCor = idxToCor(mid, numCols);

            if (target > matrix[midCor.first][midCor.second]) {
                left = mid + 1;
            }

            else if (target < matrix[midCor.first][midCor.second]) {
                right = mid - 1;
            }

            else {
                return true;
            }
        }

        return false;
    }

private:
    pair<int, int> idxToCor(int idx, int numCols) {
        return {idx / numCols, idx % numCols};
    }
};
