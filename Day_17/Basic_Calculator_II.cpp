class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        stack<int> st;
        char operation = '+';
        int currno = 0;

        for(int i = 0 ; i<n ; i++){
            char x = s[i];

            if(isdigit(x)){
                currno = currno*10 + (x-'0');
            }
            if(!isdigit(x) && !iswspace(x)  || i==n-1){
                if(operation == '-'){
                    st.push(-currno);
                }
                else if(operation == '+'){
                    st.push(currno);
                }
                else if(operation == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(currno*top);
                }
                else if(operation =='/'){
                    int top = st.top();
                    st.pop();
                    st.push(top/currno);
                }
                operation = x;
                currno = 0;
            }
        }
        int rest = 0;
        while(!st.empty()){
            rest += st.top();
            st.pop();
        }

        return rest;
    }
};