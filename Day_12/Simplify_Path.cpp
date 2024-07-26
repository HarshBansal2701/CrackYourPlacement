class Solution {
public:
    string simplifyPath(string path) {  
        string token = "";
        stack<string> st;

        stringstream ss(path);

        while(getline(ss,token,'/')){
            if(token == "" || token == "."){
                continue;
            }

            if(!st.empty() && token == ".."){
                st.pop();
            }
            else if(token != ".."){
                st.push(token);
            }
        }

        if(st.empty()){
            return "/";
        }
        string result = "";
        while(!st.empty()){
            result = '/'+ st.top() + result;
            st.pop();
        }
        return result;
    }
};