class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size(); int numCols = matrix[0].size();

        int left = 0; int right = numRows * numCols - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midRow = mid / numCols;
            int midCol = mid % numCols;

            if (target > matrix[midRow][midCol]) {
                left = mid + 1;
            }

            else if (target < matrix[midRow][midCol]) {
                right = mid - 1;
            }

            else {
                return true;
            }
        }

        return false;
    }
};
