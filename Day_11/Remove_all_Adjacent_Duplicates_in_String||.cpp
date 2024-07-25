class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        for(int i = 0 ; i<s.size() ; i++){
            if(!st.empty() && st.back().first == s[i]){
                st.back().second++;
                if(st.back().second == k){
                    st.pop_back();
                }
            }
            else{
                st.push_back({s[i], 1});
            }
        }
        string res = "";
        for(auto& it : st){
            res.append(it.second, it.first);
        }
        return res;
    }
};