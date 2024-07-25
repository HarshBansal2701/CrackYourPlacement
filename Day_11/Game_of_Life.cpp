class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // original  | New   | State
        //     0     |  0    |   0
        //     1     |  0    |   1
        //     0     |  1    |   2
        //     1     |  1    |   3

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                if(i-1>=0 && j-1>=0 && board[i-1][j-1]&1){
                    count++;
                }
                if (i - 1 >= 0 && board[i - 1][j]&1) {
                    count++;
                }
                if (i - 1 >= 0 && j + 1 < n && board[i - 1][j + 1] & 1) {
                    count++;
                }
                if (j - 1 >= 0 && board[i][j - 1] & 1) {
                    count++;
                }
                if (j + 1 <n && board[i][j + 1] & 1) {
                    count++;
                }
                if(i+1<m && j-1>=0 && board[i+1][j-1]&1){
                    count++;
                }
                if (i + 1 < m && board[i + 1][j]&1) {
                    count++;
                }
                if (i + 1 < m && j + 1 < n && board[i + 1][j + 1] & 1) {
                    count++;
                }

                if (board[i][j] == 1) {
                    if (count < 2 || count > 3) {
                        board[i][j] = 1;
                    } else{
                        board[i][j] = 3;
                    }
                }
                else{
                    if(count==3){
                        board[i][j] = 2;
                    }
                }
            }
        }

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                board[i][j] >>= 1;
            }
        }

    }
};