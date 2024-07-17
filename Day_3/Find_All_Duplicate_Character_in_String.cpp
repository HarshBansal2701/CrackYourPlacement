#include <bits/stdc++.h>
using namespace std;

vector<char> Duplicate_Char(string& s){
    vector<char> ans;
    unordered_map<char,int> mp;
    
    for(int i = 0 ; i<s.size(); i++){
        mp[s[i]]++;
        if(mp[s[i]]>1){
            ans.push_back(s[i]);
            mp[s[i]] -= s.size();
        }
    }
    return ans;
}


int main()
{
    string s = "asdfdsrjhensmdmfnhdsjndsmsdmnsazxmd";
    vector<char> ans = Duplicate_Char(s);
    
    for(int i = 0 ; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
