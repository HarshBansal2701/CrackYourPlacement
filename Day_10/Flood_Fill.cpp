class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        queue<pair<int,int>> q;
        vis[sr][sc] = true;
        int origi = image[sr][sc];
        image[sr][sc] = color;
        q.push({sr,sc});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            int x_axis[4] = {0,0,-1,1};
            int y_axis[4] = {-1,1,0,0};

            for(int i = 0 ; i<4 ; i++){
                int a = x+x_axis[i];
                int b = y+y_axis[i];

                if(a>=0 && b>=0 && a<m && b<n && !vis[a][b] && image[a][b]==origi){
                    vis[a][b] = true;
                    image[a][b] = color;
                    q.push({a,b});
                }
            }
        }
        return image;
    }
};