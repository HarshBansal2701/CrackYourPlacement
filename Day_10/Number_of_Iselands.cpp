class Solution {
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis , int x , int y){
        vis[x][y] = true;

        int r[4] = {-1,0,0,1};
        int c[4] = {0 , -1,1,0};

        for(int i = 0 ; i<4 ; i++){
            if(x+r[i]>=0 && x+r[i]<grid.size() && y+c[i]>=0 && y+c[i]<grid[0].size() &&grid[x+r[i]][y+c[i]]=='1' && !vis[x+r[i]][y+c[i]]){
                dfs(grid,vis,x+r[i],y+c[i]);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size() , vector<bool>(grid[0].size(), false));

         int ans = 0;

         for(int i = 0 ; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
         }
         return ans;
    }
};