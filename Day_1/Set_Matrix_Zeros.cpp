class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // boolean array to track weather the ith row/column contain zero or not
        vector<bool> rows(m);       
        vector<bool> col(n);

        for(int i = 0 ; i<m; i++){
            for(int j = 0 ; j<n ; j++){
                if(matrix[i][j]==0){
                    rows[i] = true;
                    col[j] = true;
                }
            }
        }

        // modify the matrix 

        for(int i =0 ;i<m ; i++){
            if(rows[i]){                     // if any element of ith row is zero modify whole ith row as zero
                for(int j = 0 ; j<n ; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int i =0 ;i<n ; i++){
            if(col[i]){                     // if any element of ith col is zero then modify all element ith col as zero 
                for(int j = 0 ; j<m ; j++){
                    matrix[j][i] = 0;
                }
            }
        }
    }
};