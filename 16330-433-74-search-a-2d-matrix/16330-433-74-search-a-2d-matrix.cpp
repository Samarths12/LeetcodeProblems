class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0;
        int end = m * n - 1;
        int mid = start + (end - start) / 2;

        while (start <= end) {
            int rowIndex = mid / n;
            int colIndex = mid % n;

            if (matrix[rowIndex][colIndex] == target)
                return true;

            else if (matrix[rowIndex][colIndex] > target)
                end = mid - 1;

            else {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }

        return false;
    }
};