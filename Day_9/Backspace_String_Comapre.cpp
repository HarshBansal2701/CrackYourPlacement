class Solution {
    string removeBackSpace(string s){
        stack<int> st;
        for(int i = 0 ; i<s.size(); i++){
            if(s[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string s1 = "";
        while(!st.empty()){
            s1+= st.top();
            st.pop();
        }
        return s1;
    }
public:
    bool backspaceCompare(string s, string t) {
        string s1 = removeBackSpace(s);
        string t1 = removeBackSpace(t);

        return s1==t1;

    }
};