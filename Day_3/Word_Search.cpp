class Solution {
    bool dfs(vector<vector<char>>& board, string word, int idx, int r,int c){
        if(idx<0){
            return true;
        }
        if(r<0 || c<0 || r >=board.size() || c>=board[0].size() || board[r][c] != word[idx]){
            return false;
        }

        board[r][c] = '#';

        int ans1 = dfs(board,word,idx-1,r,c+1);
        int ans2 = dfs(board,word,idx-1,r,c-1);
        int ans3 = dfs(board,word,idx-1,r-1,c);
        int ans4 = dfs(board,word,idx-1,r+1,c);

        board[r][c] = word[idx];
        return (ans1||ans2||ans3||ans4);

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Approach using DFS and backtracking
        int m = board.size();
        int n = board[0].size();

        for(int i = 0 ; i<m; i++){
            for(int j = 0 ; j<n ; j++){
                if(board[i][j]==word[word.size()-1]){
                    int ans = dfs(board,word,word.size()-1,i,j);
                    if(ans){
                        return ans;
                    }
                }
            }
        }
        return false;
        // TC -> (4^n)
    }
};