class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(int i = 1 ; i<strs.size(); i++){
            string temp = "";
            int j = 0;
            while(j< min(strs[i].size(), ans.size())){
                if(ans[j] != strs[i][j]){
                    break;
                }
                temp += strs[i][j];
                j++;
            }
            ans = temp;
        }

        return ans;
    }
};