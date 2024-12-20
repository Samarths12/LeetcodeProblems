class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //columns
        int totalElements = m*n;

        int startingRow = 0;
        int endingCol = n-1;
        int endingRow = m-1;
        int startingCol = 0;

        int count = 0;

        while(count<totalElements) {
            //Print starting row

            for(int i = startingCol ; i <= endingCol && count < totalElements; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
                
            }
            startingRow++;
            //Printing ending column

            for(int i = startingRow ; i <= endingRow && count < totalElements; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            //Printing ending row
            for(int i = endingCol ; i >= startingCol && count < totalElements; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            //Printing starting column
            for(int i = endingRow ; i >= startingRow && count < totalElements; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;
        
    }
};