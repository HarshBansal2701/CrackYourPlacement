//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> inorder(V,0);
        for(int i = 0 ; i<V ; i++){
            for(auto it : adj[i]){
                inorder[it]++;
            }
        }
        
        queue<int> q;
        for(int i = 0 ; i<V ; i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int fr = q.front();
            q.pop();
            ans.push_back(fr);
            
            for(auto it : adj[fr]){
                if(inorder[it]>=0){
                    inorder[it]--;
                    if(inorder[it]==0){
                        q.push(it);
                    }
                }
            }
        }
        
        
        if(ans.size()==V){
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends