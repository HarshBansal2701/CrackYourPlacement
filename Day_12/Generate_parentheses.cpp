class Solution {
    bool isValid(string s){
        // string temp;

        // for(int i = 0 ; i<s.size() ; i++){
        //     if(!temp.empty() && temp.back()=='(' && s[i]==')'){
        //         temp.pop_back();
        //     }
        //     else{
        //         temp.push_back(s[i]);
        //     }
        // }
        // if(temp.empty()){
        //     return true;
        // }
        // return false;

        int count = 0;

        for(int i = 0 ; i<s.size(); i++){
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
                if(count<0){
                    return false;
                }
            }
        }
        if(count==0){
            return true;
        }
        return false;
    }


    void solve_usingRecursion(string curr, vector<string>& ans, int n,int open,int close){
        if(curr.size() == 2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }
        if(open<=n){
        curr.push_back('(');

        solve_usingRecursion(curr,ans, n,open+1,close);
        curr.pop_back();

        }

        if(close<=open){
        curr.push_back(')');

        solve_usingRecursion(curr,ans,n,open,close+1);
        curr.pop_back();

        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";

        solve_usingRecursion(curr,ans,n,0,0);

        return ans;
    }
};