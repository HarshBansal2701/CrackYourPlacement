//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int gs = 0;
       int cs = 0;
       
       for(int i = 0 ; i<n ;i++){
           gs += p[i].petrol;
           cs+= p[i].distance;
       }
       if(gs<cs){
           return -1;
       }
       int total = 0;
       int result = 0;
       
       for(int i = 0 ; i<n ; i++){
           total +=p[i].petrol - p[i].distance;
           if(total<0){
                total = 0;
                result = i+1;
           }
       }
       return result;
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends