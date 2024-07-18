//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void dfs(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '0';
        
        int r[8] = {-1,-1,-1,0,0,1,1,1};
        int c[8] = {-1,0,1,1,-1,1,0,-1};
        
        for(int i = 0 ; i<8 ; i++){
            int x = row + r[i];
            int y = col + c[i];
            
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]=='1'){
                dfs(grid,x,y);
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends