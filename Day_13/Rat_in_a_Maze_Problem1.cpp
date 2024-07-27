//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    void help(vector<vector<int>> &mat, int i,int j,string temp,vector<string>& ans){
        int n = mat.size();
        if(i==n-1 && j == n-1){
            ans.push_back(temp);
            return;
        }
        
        if(i+1<n && mat[i+1][j]==1){
            temp.push_back('D');
            mat[i+1][j] = 0;
            help(mat,i+1,j,temp,ans);
            mat[i+1][j] = 1;
            temp.pop_back();
        }
        
        if(i-1>=0 && mat[i-1][j]==1){
            temp+='U';
            mat[i-1][j] = 0;
            help(mat,i-1,j,temp,ans);
            mat[i-1][j] = 1;
            temp.pop_back();
        }
        
        if(j+1<n && mat[i][j+1]==1){
            temp+='R';
            mat[i][j+1] = 0;
            help(mat,i,j+1,temp,ans);
            mat[i][j+1] = 1;
            temp.pop_back();
        }
        
        if(j-1>=0 && mat[i][j-1]==1){
            temp+='L';
            mat[i][j-1] = 0;
            help(mat,i,j-1,temp,ans);
            mat[i][j-1] = 1;
            temp.pop_back();
        }
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your chode goes here
        vector<string> ans;
        int n = mat.size();
        
        if(mat[0][0]==0 || mat[n-1][n-1]==0){
            return ans;
        }
        mat[0][0] = 0;
        
        help(mat,0,0,"",ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends