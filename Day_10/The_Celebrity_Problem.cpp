//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // vector<int> freq(n,0);
        // vector<bool> who_know(n,false);
        
        // for(int i = 0 ; i<n ; i++){
        //     for(int j = 0 ; j<n ; j++){
        //         if(M[i][j]){
        //             freq[j]++;
        //         who_know[i] = true;
        //         }
        //     }
        // }
        
        // for(int i = 0 ; i<n ;  i++){
        //     if(!who_know[i] && freq[i]==n-1){
        //         return i;
        //     }
        // }
        // return -1;
        
        
        stack<int> st;
        
        for(int i = 0; i<n ; i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(M[a][b]){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        int ans = st.top();
        int zero = 0;
        for(int i = 0 ; i<n ; i++){
            if(M[ans][i]==0){
                zero++;
            }
        }
        if(zero != n){
            return -1;
        }
        
        int one = 0;
        
        for(int i = 0 ; i<n ; i++){
            if(M[i][ans]==1){
                one++;
            }
        }
        if(one != n-1){
            return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends