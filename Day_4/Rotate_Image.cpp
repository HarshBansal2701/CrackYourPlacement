class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0 ; i<m;i++){
            for(int j = i+1 ; j<n ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0 ; i<m ; i++){
            int x = 0;
            int y = n-1;
            while(x<y){
                swap(matrix[i][x++], matrix[i][y--]);
            }
        }
        // TC -> O(N*N)
    }
};