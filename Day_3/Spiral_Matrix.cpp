class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Approach -> playing with indexes
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int count = 0;

        int start_row = 0;
        int end_row = m-1;
        int start_col = 0;
        int end_col = n-1;

        while(count < m*n){
            // traverse left to right
            for(int i = start_col ; i<=end_col && count < m*n; i++){
                ans.push_back(matrix[start_row][i]);
                count++;
            }
            start_row++;

            for(int i = start_row ; i<=end_row && count < m*n ; i++){
            // Traverse downwords
                ans.push_back(matrix[i][end_col]);
                count++;
            }
            end_col--;

            for(int i = end_col ; i>=start_col && count < m*n; i--){
            // Traverse right to left
                ans.push_back(matrix[end_row][i]);
                count++;
            }
            end_row--;

            for(int i = end_row ; i>= start_row && count < m*n ; i--){
            // Traverse upwords
                ans.push_back(matrix[i][start_col]);
                count++;
            }
            start_col++;
        }
        return ans;
        // TC -> O(m*n)
    }
};