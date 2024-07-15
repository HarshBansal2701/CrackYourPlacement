//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    // Method -> (using sliding window after sorting)
    // in sorted array the difference b/w last and first element id the difference b/w smallest and largest element of that array 
    // maintain the window of size m
    
    sort(a.begin(), a.end());
    
    long long min_diff = INT_MAX;
    
    for(int i = m-1 ; i<n ; i++){
        min_diff = min(min_diff , a[i]-a[i-m+1]);
    }
    return min_diff;
    
    // Method => TC-> O(n*log(n)) , SC -> O(1)
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends